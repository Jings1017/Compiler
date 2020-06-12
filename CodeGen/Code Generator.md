# Code Generator

### 執行方式

```

// 個別測資的結果
./mycompiler < input/in13_monster.go // 產生.j
make Main.class
make run // 將結果印在terminal上

// 看13筆測資的結果
make judge

//
make clean

```

### 程式說明

基本上是對Yacc做擴充，
建立hw3.j，並把相對的組合語言寫進hw3.j

Compare的設計:
在做compare的時候(>,=,<)
會先呼叫 void compare(char op[10])
針對對應的operator做不同的處理

Label的設計:
Label_name_ + label_count
每做完一組指令，對label_count作相對應的加法