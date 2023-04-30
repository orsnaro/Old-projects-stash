"""
								  Coder : Omar
								  Version : v1.0B
								  version Date :  28 / 4 / 2023
								  Code Type : Key Recorder - general use 
								  Title : KeyRec 
								  Interpreter : cPython  v3.11.0 [Compiler : MSC v.1933 AMD64]
								  EXE using : pyinstaller module
"""

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


# Replay the key presses until a specific button is pressed
def replay(events, replay_key= 'f6'):
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
					keyboard.play([event])
					time.sleep(round(random.uniform(0.1, 0.4), 2))


# Main function
if __name__ == '__main__':
	events = record(start_key= 'f10')
	replay(events , replay_key= 'f12')