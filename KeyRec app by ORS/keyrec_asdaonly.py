import win32api
import win32gui
import win32con
import win32process
import keyboard
import random
import time
import sys


def get_keys_map_dict() -> dict:
	# Create a dictionary that maps key names to virtual key codes and scan codes
	key_mapping = {}
	key_names = [
					'\x00'      , 'ctrl'    , 'shift'        , 'alt'        , 
					'alt_gr'    , 'shift_r' , 'ctrl_r'       , 'left'       , 
					'up'        , 'right'   , 'down'         , 'enter'      , 
					'esc'       , 'tab'     , 'space'        , 'backspace'  , 
					'caps_lock' , 'num_lock', 'print_screen' , 'scroll_lock',
					'pause'     , 'insert'  , 'delete'       , 'home'       , 
					'end'       , 'page_up' , 'page_down'    , 'f1'         , 
					'f2'        ,'f3'       , 'f4'           ,  'f5'        ,
					'f6'        , 'f7'      ,'f8'            , 'f9'         ,
					'f10'       , 'f11'     , 'f12'          , 'cmd'        , 
					'cmd_r'     , 'menu'    , 'context_menu' , 'shift_lock' ]
					

	for key_name in key_names:
		vk_code = win32api.MapVirtualKey(ord(key_name), 0)
		scan_code = win32api.MapVirtualKey(ord(key_name), win32con.MAPVK_VK_TO_VSC)
		key_mapping[key_name] = {"vk_code": vk_code, "scan_code": scan_code}

	return key_mapping


# Record the key presses
def record(start_key='f5'):
    events: list = []
    print("~~~~~~~~~ WELCOME TO KeyRec - Only Asda v2.0B by ORS ~~~~~~~~~")
    print(
        f"\n-> '{start_key}' to start record. \n-> '{start_key}' again stops record.")
    while True:
        if keyboard.is_pressed(start_key):
            print("\nSTARTED RECORDING...")
            time.sleep(1)
            events = keyboard.record(until=start_key)
            print("END RECORDING...")
            break
    events_done = events[:-1]
    print(f"\n\n\nrecorded keys : \n {events_done}")
    return events_done


# Replay the key presses to a specific application identified by its PID
def replay_in_window(events,  key_mapping: dict, replay_key: str = 'f6', stop_key: str = 'f10', window_name: str = "Asdastory (ME)"):

    # Set the window name you want to search for
    window_name = "Asdastory (ME)"

    # Get a handle to the application's main window
    hwnd = win32gui.FindWindow(None, window_name)
    # Get the process ID of the window
    pid = win32process.GetWindowThreadProcessId(hwnd)[1]

    # Get the handle to the window
    hwnd = win32gui.FindWindowEx(0, 0, None, window_name)

    # Get the dimensions of the application's main window
    rect = win32gui.GetWindowRect(hwnd)
    x, y, _, _ = rect

    print(
        f"\n\n\n-> '{replay_key}' to start replay. \n-> '{replay_key}' again pauses replay")

    while True:

        if keyboard.is_pressed(replay_key):
            print("\nSTART RE-PLAYING...")
            time.sleep(0.2)

            while True:
                for event in events:
                    if keyboard.is_pressed(replay_key):
                        print("PAUSED RE-PLAYING...")
                        print(
                            f"\n  -> '{replay_key}' again to UN-PAUSE")
                        print(
                            f"  -> '{stop_key}'  to STOP & EXIT ")

                        if keyboard.is_pressed(replay_key):
                            pass

                        elif keyboard.is_pressed(stop_key):

                            print(
                                "\n\n\nexiting KeyRec by ORS...  \nwas made for my childhood game asda-story <3 ...")
                            sys.exit(0)  # success

                    # convert Keyboard library events  to win32api events
                    key_name = keyboard.all_scancodes[event.scan_code]
                    vk_code = key_mapping[key_name]["vk_code"]
                    scan_code = key_mapping[key_name]["scan_code"]

                    if event.event_type == keyboard.KEY_DOWN:
                        win32api.keybd_event(vk_code, scan_code, 0, 0)

                    elif event.event_type == keyboard.KEY_UP:
                        win32api.keybd_event(
                            vk_code, scan_code, win32con.KEYEVENTF_KEYUP, 0)

                    time.sleep(round(random.uniform(0.1, 0.4), 2))


if __name__ == '__main__':

    events = record(start_key='f10')

    key_mapping = get_keys_map_dict()

    replay_in_window(events, key_mapping=key_mapping, replay_key='f12')
