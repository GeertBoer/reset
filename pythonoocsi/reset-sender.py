from oocsi import OOCSI
import time

uname = input("Type your username: ")

o = OOCSI("PC" + uname, 'oocsi.id.tue.nl')

print("\n#############################\nPYTHON PROMPT -> RESET DEVICE\n#############################\n")

while 1:
	print("What do you want to send?")
	print("(A)chievement, \n(G)et creative, \n(F)unfact, \n(J)oke, \n(O)ffice info, \n(Q)uestion, \nGet from (L)ist")
	print("Or type \"quit\" to quit\n")

	val = input("Type your choice: ")
	choice = ""

	if val in ['A', 'a', 'Achievement', 'achievement']:
	    choice = "achievement"
	elif val in ['F','f	','Funfact', 'funfact']:
	    choice = "funfact"
	elif val in ['G', 'g', 'Getcreative', 'getcreative']:
	    choice = "getcreative"
	elif val in ['J', 'j', 'Joke', 'joke']:
	    choice = "joke"
	elif val in ['O', 'o', 'Officeinfo', 'officeinfo']:
	    choice = "officeinfo"
	elif val in ['Q','q','Question', 'question']:
	    choice = "question"
	elif val in ['L', 'l']:
	    choice = "getfromlist"
	elif val == "quit":
		o.stop()
		quit()
	else:
		o.stop()
		quit()

	print("You chose: " + choice)
	msg = input("\nWhat message do you want to send? Please type or leave empty: ")
	if msg == "":
		print("Not sending anything...")
	else:
		print("Sending " + choice + ": " + msg)
		message = {}
		message[choice] = msg
		o.send('esp-testchannel', message)
		time.sleep(2)
		print("\n\n")
