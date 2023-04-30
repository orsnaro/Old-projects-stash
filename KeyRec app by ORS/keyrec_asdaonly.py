import win32api
import win32gui
import win32con
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