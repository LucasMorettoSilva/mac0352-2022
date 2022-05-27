HOST_SERVER=ep2-server

SRC_DIR=src
INCLUDE_DIR=includes
BUILD_DIR=build
BIN_DIR=bin

MKDIR_P ?= mkdir -p
CPP=g++
CFLAGS=-I$(INCLUDE_DIR) -lm -pthread

SRC_EXT=.cpp
INC_EXT=.hpp
OBJ_EXT=$(SRC_EXT).o

DOCKER_CMP=docker-compose

SERVER_EXEC ?= $(BIN_DIR)/server
CLIENT_EXEC ?= $(BIN_DIR)/client
SRCS := $(shell find $(SRC_DIR) -name *$(SRC_EXT))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

_CLIENT_OBJS  = ep2-client util client-functionality packages server-io game-board
__CLIENT_OBJS = $(addsuffix $(OBJ_EXT), $(_CLIENT_OBJS))
CLIENT_OBJS   = $(addprefix $(BUILD_DIR)/$(SRC_DIR)/, $(__CLIENT_OBJS))

_SERVER_OBJS  = ep2-server util server-functionality server-io packages
__SERVER_OBJS = $(addsuffix $(OBJ_EXT), $(_SERVER_OBJS))
SERVER_OBJS   = $(addprefix $(BUILD_DIR)/$(SRC_DIR)/, $(__SERVER_OBJS))

PORT ?= 8080

.PHONY: clean all run-server run-client docker

all: bin

run-server: all
	$(SERVER_EXEC) $(PORT)

run-client: all
	$(CLIENT_EXEC) $(HOST_SERVER) $(PORT)

docker:
	$(DOCKER_CMP) down
	$(DOCKER_CMP) up --build

bin: $(OBJS)
	$(MKDIR_P) ./$(BIN_DIR)
	$(CPP) $(CLIENT_OBJS) $(CFLAGS) -o $(CLIENT_EXEC)
	$(CPP) $(SERVER_OBJS) $(CFLAGS) -o $(SERVER_EXEC)

$(BUILD_DIR)/%$(OBJ_EXT): %$(SRC_EXT)
	$(MKDIR_P) $(dir $@)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(BIN_DIR)

-include $(DEPS)
