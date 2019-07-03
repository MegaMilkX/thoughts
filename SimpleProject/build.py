
PROJECT_CONFIG_EXTENSION = "katana"

import glob
import os
import errno
import subprocess
try:
    from configparser import ConfigParser
except ImportError:
    from ConfigParser import ConfigParser  # ver. < 3.0

projectList = []
projectCount = 0
def listProjectFiles():
	global projectList
	global projectCount
	mask = "*." + PROJECT_CONFIG_EXTENSION
	projectList = glob.glob(mask)
	projectCount = len(projectList)
	if(projectCount == 0):
		print("No " + mask + " files found in working directory. Abort.")
		stop
	elif(projectCount > 1):
		print("Project directory should contain only one " + mask + " file")
		return
	
	return

listProjectFiles()

for projIni in projectList:
	config = ConfigParser()
	config.read(projIni)
	print(config.get('General', 'title'))
	print(config.get('General', 'input_bindings'))
	print(config.get('General', 'command_bindings'))
	print(config.get('General', 'entry_session'))
	print(config.get('General', 'viewport'))
	
	try:
		os.mkdir(os.path.splitext(os.path.basename(projIni))[0] + '_build')
	except OSError as ex:
		if ex.errno != errno.EEXIST:
			raise
		pass

try:
	ret = subprocess.check_call("cmake")
except OSError as ex:
	print("Failed to launch cmake: %i", ex.errno);
	