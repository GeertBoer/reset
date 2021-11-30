# Copyright (c) 2017 Mathias Funk
# This software is released under the MIT License.
# http://opensource.org/licenses/mit-license.php

from oocsi import OOCSI
import time
from random import random

o = OOCSI('PythonScript', 'oocsi.id.tue.nl')

while 1:   
	message = {}
	#message['question'] = "How are you?"
	message['funfact'] = "Lauren is een beetje moe ondanks dat hij anderhalf uur langer geslapen heeft."
	# message['achievement'] = "Good job nerd"
	# message['getcreative'] = "Draw a penis!"
	# message['joke'] = "You are a joke Bob."
	o.send('esp-testchannel', message)

	# wait and continue
	time.sleep(100)
