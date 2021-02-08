#!/bin/bash

# get date: ex. 1970.01.01
#now=$(LANG=en_us_88591; date "+%Y.%m.%d")

# get full date : ex. Thurs Jan 1 00:00:00 KST 1970
#now=$(LANG=en_us_88591; date)

# get date + time: ex. 1970.01.01 00:00:00
now=$(LANG=en_us_88591; date "+%Y.%m.%d %T")
#echo $now

# get ALL user inputs
message="$*"

# git commit with date + message
git commit -m "$today $message"
# push if wanted
#git push origin master
