# Compiler2020 HW1 < Lex >

## Instruction

```
$ lex compiler_hw1.l
$ cc lex.yy.c -ll
./a.out test.c
```

## Note

BEGIN str after getting  print/println/string

rules:
``` 
<str>\"/{id}
<end>{id}/\"  
```

BEGIN comment after getting commentln

rules:
```
<comment>([^("*/")^("\n")]|[+=-~!@#$%^&*()<>]*)*("*/")
<comment>([^("*/")^("\n")]|[+=-~!@#$%^&*()<>]*)*("\n")
```

