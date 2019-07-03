import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument('path', metavar='DIRECTORY', help='path to a preferably empty directory')
args = parser.parse_args()



try:
	os.mkdir(args.path)
except OSError as ex:
	if ex.errno != errno.EEXIST:
		raise
	pass