CXX := g++
CXXFLAGS := -Wall -std=c++23 -Iinclude  # -Iinclude で include/ を検索パスに追加
LDFLAGS := 

# ディレクトリとファイル
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
TARGET := kilo

# 全ソースファイル (.cpp)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# オブジェクトファイル (.o) に変換
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# デフォルトターゲット
all: $(TARGET)

# リンクして最終実行ファイルを生成
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# コンパイル: .cpp -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# クリーン
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean