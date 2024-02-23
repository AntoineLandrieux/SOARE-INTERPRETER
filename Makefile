#  _____  _____  ___  ______ _____
# /  ___||  _  |/ _ \ | ___ \  ___|
# \ `--. | | | / /_\ \| |_/ / |__
#  `--. \| | | |  _  ||    /|  __|
# /\__/ /\ \_/ / | | || |\ \| |___
# \____/  \___/\_| |_/\_| \_\____/
# Antoine LANDRIEUX
# <https://github.com/AntoineLandrieux/SOARE>
# GNU General Public License v3.0
# https://www.gnu.org/licenses/gpl-3.0.html

# COMPILER
CC = g++

# OUTPUT
EXE = soare.exe

# DIRECTORIES
SOURCE_DIR = app
BINARY_DIR = bin
LIBRARY_DIR = lib
INCLUDE_DIR = include

# FLAGS
CFLAGS = -Wall -Wextra -Waddress

.PHONY: all

all: makedir $(EXE)

makedir:
	mkdir -p $(BINARY_DIR)

$(EXE):
	$(CC) $(SOURCE_DIR)/*.cpp -o $(BINARY_DIR)/$(EXE) -I $(INCLUDE_DIR) -L $(LIBRARY_DIR) -lsoare1
