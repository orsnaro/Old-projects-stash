combine this with pid to send to specif app only even if its window not focused

To send the recorded key presses to a specific application identified by its process ID (PID), you can modify the replay function to use the win32api and win32gui modules to get a handle to the application's main window, and then use the SendMessage function to send simulated keyboard events to the window.

Here's an example of how to modify the replay function to send the key presses to a specific application identified by its PID:

```python

import win32api
import win32gui
import keyboard
import random
import time
import sys

# Record the key presses
def record( start_key= 'f5'):
	events : list = []
	print("~~~~~~~~~ WELCOME TO KeyRec v1.0B by ORS ~~~~~~~~~")
	print (f"\n-> press '{start_key}' to start record. press '{start_key}' again to stop recording")
	while True :
		if keyboard.is_pressed(start_key) :
			print ("\nSTARTED RECORDING...")
			time.sleep(1)
			events = keyboard.record(until= start_key)
			print ("END RECORDING...")
			break
	events_done = events[:-1]
	print (f"\n\n\nrecorded keys : \n {events_done}")
	return events_done


# Replay the key presses to a specific application identified by its PID
def replay(events, pid, replay_key= 'f6'):
	# Get a handle to the application's main window
	hwnd = win32gui.FindWindowEx(0, 0, None, None)
	while hwnd:
	    if win32api.GetWindowThreadProcessId(hwnd)[1] == pid:
	        break
	    hwnd = win32gui.FindWindowEx(0, hwnd, None, None)

	print (f"\n\n\n-> press '{replay_key}' to start replay. press '{replay_key}' again to stop replaying")
	while True:
		if keyboard.is_pressed(replay_key):
			print ("\nSTART RE-PLAYING...")
			time.sleep(0.2)
			while True :
				for event in events:
					if keyboard.is_pressed(replay_key):
						print ("END RE-PLAYING...")
						print("\n\n\nexiting KeyRec by ORS...  \nwas made for asda-story...")
						sys.exit(0) #success
					# Send the key press to the application
					win32api.SendMessage(hwnd, win32con.WM_CHAR, event.scan_code, 0)
					time.sleep(round(random.uniform(0.1, 0.4), 2))


# Main function
if __name__ == '__main__':
	pid = 1234  # Replace with the process ID of the target application
	events = record(start_key= 'f10')
	replay(events, pid, replay_key= 'f12')
```
In this example, we modify the replay function to take an additional argument pid that specifies the process ID of the target application. We use the win32api and win32gui modules to get a handle to the application's main window, as in the previous example.

To send the recorded key presses to the application, we use the SendMessage function to send a WM_CHAR message to the application's main window, passing the key's scan code as the wParam parameter. We also wait for a short time (100ms in this example) to give the application time to process the message before sending any more key presses.

Note that this example assumes that the recorded key presses were captured using the keyboard library's record function. If you are using a different method to capture the key presses, you may need to modify the code accordingly.

I hope this helps! Let me know if you have any further questions.



# this will work even if app is minimized?

No, the code I provided will not work if the target application's main window is minimized. When a window is minimized, it is not displayed on the screen and its message loop is not active, so sending simulated keyboard events to it using the SendMessage function will not have any effect.

To send key presses to a minimized window, you can use the keybd_event function from the win32api module to simulate keyboard events at the system level. This function sends keyboard events directly to the input queue, bypassing the message loop of the target window.

Here's an example of how to modify the replay function to use keybd_event instead of SendMessage to send key presses to a minimized window:

```python

import win32api
import win32gui
import keyboard
import random
import time
import sys

# Record the key presses
def record( start_key= 'f5'):
	events : list = []
	print("~~~~~~~~~ WELCOME TO KeyRec v1.0B by ORS ~~~~~~~~~")
	print (f"\n-> press '{start_key}' to start record. press '{start_key}' again to stop recording")
	while True :
		if keyboard.is_pressed(start_key) :
			print ("\nSTARTED RECORDING...")
			time.sleep(1)
			events = keyboard.record(until= start_key)
			print ("END RECORDING...")
			break
	events_done = events[:-1]
	print (f"\n\n\nrecorded keys : \n {events_done}")
	return events_done


# Replay the key presses to a specific application identified by its PID
def replay(events, pid, replay_key= 'f6'):
	# Get a handle to the application's main window
	hwnd = win32gui.FindWindowEx(0, 0, None, None)
	while hwnd:
	    if win32api.GetWindowThreadProcessId(hwnd)[1] == pid:
	        break
	    hwnd = win32gui.FindWindowEx(0, hwnd, None, None)

	# Get the dimensions of the application's main window
	rect = win32gui.GetWindowRect(hwnd)
	x, y, _, _ = rect

	print (f"\n\n\n-> press '{replay_key}' to start replay. press '{replay_key}' again to stop replaying")
	while True:
		if keyboard.is_pressed(replay_key):
			print ("\nSTART RE-PLAYING...")
			time.sleep(0.2)
			while True :
				for event in events:
					if keyboard.is_pressed(replay_key):
						print ("END RE-PLAYING...")
						print("\n\n\nexiting KeyRec by ORS...  \nwas made for asda-story...")
						sys.exit(0) #success
					# Simulate the key press at the system level
					win32api.keybd_event(event.scan_code, 0, 0, 0)
					win32api.keybd_event(event.scan_code, 0, win32con.KEYEVENTF_KEYUP, 0)
					time.sleep(round(random.uniform(0.1, 0.4), 2))


# Main function
if __name__ == '__main__':
	pid = 1234  # Replace with the process ID of the target application
	events = record(start_key= 'f10')
	replay(events, pid, replay_key= 'f12')
```

In this example, we modify the replay function to use the keybd_event function to simulate keyboard events at the system level. We also retrieve the dimensions of the application's main window using the GetWindowRect function from the win32gui module, so we can specify the coordinates of the simulated key press.

To simulate a key press, we call win32api.keybd_event with the following arguments:

event.scan_code: The scan code of the key to simulate.
0: This is the hardware scan code of the key, which we set to 0 to use the default value.
0 or win32con.KEYEVENTF_EXTENDEDKEY: This specifies whether the key is an extended key, which we set to 0 for non-extended keys.
0: This is a reserved parameter, which we set to 0.
We then follow up with a second call to win32api.keybd_event with the same arguments, but with the KEYEVENTF_KEYUP flag set in the dwFlags parameter, to simulate the release of the key.

Note that simulating keyboard events at the system level can have unintended consequences, such as triggering system-wide keyboard shortcuts or interfering with other applications. Use this approach with caution, and test thoroughly before deploying in a production environment.

I hope this helps! Let me know if you have any further questions.

# so better i don't minimize?  what about  if another window is in focus not the wanted app but my wanted app not minimized?

# i need the inpur key board from a program to go to mimized winodw with out focus on it or get it to forground (work almost totally in background except you see it flashes in taskbar)

In order to send keyboard input to a minimized window without making it active, you can use the PostMessage() function from the win32gui module to simulate a keystroke message, instead of the keybd_event() function from win32api.

When you use keybd_event() to send a keystroke message, the message is sent directly to the window that has the input focus, or to the window that is currently active. If the window is minimized or not active, the message will not be processed.

On the other hand, when you use PostMessage() to simulate a keystroke message, the message is placed in the message queue of the specified window, regardless of whether the window is active or not. The message will be processed when the window becomes active again, or when the message queue is processed by the system.

Here's an example code snippet that demonstrates how to use PostMessage() to simulate a keystroke message and send it to a minimized window:

```python
					if event.event_type == keyboard.KEY_DOWN:
						msg = win32con.WM_KEYDOWN
						wparam = vk_code
						lparam = (scan_code << 16) | 1
						win32gui.PostMessage(hwnd, msg, wparam, lparam)

					elif event.event_type == keyboard.KEY_UP:
						msg = win32con.WM_KEYUP
						wparam = vk_code
						lparam = (scan_code << 16) | (1 << 31)
						win32gui.PostMessage(hwnd, msg, wparam, lparam)
```


there is another function in the win32gui module called SendMessage() that is similar to PostMessage(). Both functions are used to send messages to a window, but they differ in their behavior and usage.

The SendMessage() function sends a message directly to the target window's message queue and waits for the window to process the message before returning. This means that SendMessage() is a synchronous function that blocks the calling thread until the target window has processed the message. If the target window is not responding or is busy, the calling thread may be blocked for a significant amount of time.

On the other hand, the PostMessage() function sends a message to the target window's message queue and immediately returns, allowing the calling thread to continue executing without waiting for the target window to process the message. This means that PostMessage() is an asynchronous function that does not block the calling thread. The target window will process the message at some later time, typically when it enters its message loop.

In general, SendMessage() is used for immediate communication with a window, while PostMessage() is used for delayed or non-critical communication. Which function to use depends on the specific use case and requirements of your application.




1