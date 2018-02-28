Respuestas:

1. Cada uno de los pasos va a generar un archivo intermedio antes del ejecutable.

2. El preprocesador agergó funciones o rutinas que no estaban definidas en los archivos originales. Por ejemplo printf o add_numbers:

# 5 "calculator.h" 2
int add_numbers(int a, int b);
# 2 "calculator.c" 2

int main(int argc, char **argv) {
  int sum;
  sum = add_numbers(31, 11);
  printf("I know how to add! 31 + 11 is %d\n", sum);
  return 0;
}

int add_numbers(int a, int b){
  return a + b;
}


3. Para el caso de add_numbers que sí está definida serian estas lineas:

add_numbers:
.LFB1:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	mov	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [ebp+8]
	add	eax, edx
	pop	ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc

4. Los símbolos en calculator.o son T y U, la T significa que puede ser llamado desde fuera mientras que la U muestra que a esta altura se encuentra indefinida.

alumno@inforcytb22:~/HOcompiled/compilador$ nm calculator.o
0000003d T add_numbers
00000000 T main
         U printf

5. Al generarse el ejecutable se linkea a printf a una biblioteca en particular 

0804a00c W data_start
0804a018 b dtor_idx.6161
080483c0 t frame_dummy
080483e4 T main
         U printf@@GLIBC_2.0




