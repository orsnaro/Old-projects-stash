
"""
								  Coder : Omar
								  Version : v2.0B
								  version Date :  29 / 4 / 2023
								  Code Type : key recorder app for specific app window
								  Title : KeyRec-Asda
								  Interpreter : cPython  v3.11.0 [Compiler : MSC v.1933 AMD64]
								  EXE using : pyinstaller module
"""
#TODO : GUI it
#TODO : OOP it 
#TODO : mouse recording

import scan_vk_codes_dicts as codes
import win32api
import win32gui
import win32con
import win32process
import keyboard
import random
import time
import sys
import os


def get_keys_map_dict() -> dict:
	# Create a dictionary that maps key names to virtual key codes and scan codes
	# scan_codes_dict = codes.SCAN_CODE
	vk_codes_dict = codes.VK_CODES
	key_mapping: dict = {}

# NOTE: I dont need to use win32api.MapVirtualKey() here to get v_keys
# since i have the  dict already i can make scand codes then map directly

	for key_name, key_code in vk_codes_dict.items() :
		scan_code = win32api.MapVirtualKey(key_code,0)#map virtual key to scan code
		key_mapping[key_name] = {"vk_code": key_code, "scan_code": scan_code}

	return key_mapping


# Record the key presses
def record(start_key='f5'):
	events: list = []
  
	print(
		f"\n\n\n-> '{start_key}' to start record. \n-> '{start_key}' again stops record.")
	while True:
		if keyboard.is_pressed(start_key):
			print("\nSTARTED RECORDING...")
			time.sleep(1)
			events = keyboard.record(until=start_key)
			print("END RECORDING...")
			break
	events_done = events[:-1]
 
	os.system("cls")
	print(f"\n\n\nrecorded keys : \n {events_done}")
	return events_done


# Replay the key presses to a specific application identified by its PID
def replay_in_window(events,  key_mapping: dict, replay_key: str = 'f6', stop_key: str = 'f10', window_name: str = "Asdastory (ME)"):

	# Set the window name you want to search for

	# Get a handle to the application's main window
	hwnd = win32gui.FindWindow(None, window_name)
 
	tid , pid = win32process.GetWindowThreadProcessId(hwnd)
	crnt_thread_id = win32api.GetCurrentThreadId()
	target_proc_id , _ = win32process.GetWindowThreadProcessId(hwnd)
 
	# now two threads can share input like keyboard state and crnt focus window
	win32process.AttachThreadInput(crnt_thread_id , target_proc_id , True)
 
	# Get the dimensions of the application's main window
	rect = win32gui.GetWindowRect(hwnd)
	x, y, _, _ = rect
	print(rect)

	print(
		f"\n\n\n-> '{replay_key}' to start replay. \n-> '{replay_key}' again pauses replay")

	while True:
		if keyboard.is_pressed(replay_key):
			print("\nSTART RE-PLAYING...")
			time.sleep(0.2)

			while True:
				#bring window you want to focus and show  it at top most
				# win32gui.SetForegroundWindow(hwnd)
				for event in events:
					# convert gotten physical key code( scan code ) to vk code and pass booth
					scan_code = event.scan_code
					vk_code   = win32api.MapVirtualKey( scan_code , 1) #map or convert  scan code to vk code
					key_name  = next((key for key , val in codes.VK_CODES.items() if val == vk_code), None) #return first elmnt if there is multiple
					#NOTE: clearing ambiguity of  next() name! 
					# When you create an iterator object from an iterable using the iter() function, the iterator is positioned before the first element in the sequence.

					if event.event_type == keyboard.KEY_DOWN:
						msg = win32con.WM_KEYDOWN
						wparam = vk_code #WPARAM = WORD PARAMETER but 32bit actually XD use .bit_length()
						lparam = (scan_code << 16) | 1 #LONG PARAMETER : #FOR KEY DOWN  RMB must set to 1 (little endian)
						win32gui.PostMessage(hwnd, msg, wparam, lparam)

					elif event.event_type == keyboard.KEY_UP:
						msg = win32con.WM_KEYUP
						wparam = vk_code
						# scan_code is 8bit originally
						lparam = (1 << 31) | (scan_code << 16)#little endian :FOR KEY UP LMB must be set to 1 
						win32gui.PostMessage(hwnd, msg, wparam, lparam)

					time.sleep(round(random.uniform(0.1, 0.4), 2))
	
					if keyboard.is_pressed(replay_key):
						keyboard.release(replay_key)
						time.sleep(0.2)
						os.system("cls") 
						print("\nPAUSED RE-PLAYING...")
						print(
							f"\n  -> '{replay_key}' again to UN-PAUSE")
						print(
							f"  -> '{stop_key}'  to STOP & EXIT ")
		
						while True :
							if keyboard.is_pressed(replay_key):
								keyboard.release(replay_key)
								time.sleep(0.2)
								print("\nUN-PAUSED continue RE-PLAYING...")
								break

							elif keyboard.is_pressed(stop_key):
								time.sleep(0.2)
								print(
									"\n\n\nexiting KeyRec by ORS...  \nwas made for my childhood game asda-story <3 ... \nfor win not for unix...")
		
								# Detach i/p crnt thread from i/p target_proc_thread 
								win32process.AttachThreadInput(crnt_thread_id , target_proc_id , False)
								sys.exit(0)  # success

def main_keyrec() -> bool :
	print("\t\t\t\t~~~~~~~~~ WELCOME TO (KeyRec - Asda) v2.0B by ORS ~~~~~~~~~\n")
	print(
	"""
			Coder : Omar
			Version : v2.0B
			Code Type : key recorder app for specific app window
			Title : KeyRec-Asda
			Interpreter : cPython  v3.11.0 [Compiler : MSC v.1933 AMD64]
			EXE using : pyinstaller module
   
			~WORKS IF Your GAME OR APP is out of focus even if minimized!! <3~
	""")

	choice =  int(input("\n\n\n (1) Use on custom window \n (2) Use on Asda Story window \r\n choice: "))
	events = record(start_key='f10')
	key_mapping = get_keys_map_dict()
 
	if choice == 1 :
		window_name = str(input("Enter Your Window name: \n")).strip()
		replay_in_window(events, key_mapping=key_mapping, replay_key='f12',window_name= window_name)
	else :
		replay_in_window(events, key_mapping=key_mapping, replay_key='f12')
	
	return True #success


if __name__ == '__main__':
	main_keyrec()
