from oocsi import OOCSI
import time

o = OOCSI('PythonScript', 'oocsi.id.tue.nl')

print("\n#############################\nPYTHON PROMPT -> RESET DEVICE\n#############################\n")

while 1:
	print("What do you want to send?")
	print("(A)chievement, \nget(C)reative, \n(F)unfact, \n(J)oke, \n(Q)uestion")
	print("Or type \"quit\" to quit\n")

	val = input("Type your choice: ")
	choice = ""

	if val in ['A', 'a', 'Achievement', 'achievement']:
	    choice = "achievement"
	elif val in ['C', 'c', 'Getcreative', 'getcreative']:
	    choice = "getcreative"
	elif val in ['F','f','Funfact', 'funfact']:
	    choice = "funfact"
	elif val in ['J', 'j', 'Joke', 'joke']:
	    choice = "joke"
	elif val in ['Q','q','Question', 'question']:
	    choice = "question"
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
