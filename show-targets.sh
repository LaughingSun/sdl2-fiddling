#!/bin/bash
find src -type f -name 'Makefile' |sed 's#src/\(.*\)/.*#\1 #' |sed 's#/#-#g'
