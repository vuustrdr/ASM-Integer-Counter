
/* demonstration of the use of asm instructions within C prog */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{	
	int X; //x is number of integers needed for input
	int seq;

	int pcount = 0;
	int ncount = 0;
	int zerocount = 0;

	char msg[] = "Enter how many integers: ";
	char sequence[] = "Enter an Integer: ";   // declare variables in 
	char fmt[] = "%d";
	char inputcontrol[] = "Please enter another integer: ";

	char poscount[] = "No. of Positive integers: ";
	char negcount[] = " No. of Negative integers: ";
	char zercount[] = " No. of Zeros: ";



	_asm
	{	
		start:
			lea eax, msg
			push eax
			call printf
			pop eax

			lea eax, X
			push eax
			lea eax, fmt
			push eax	
			call scanf 
			add esp, 8

			mov ecx, X

			mov eax, X
			cmp eax, 0
			jl negativeinteger
			jg loop1

		negativeinteger:
			lea eax, inputcontrol
			push eax
			call printf 
			pop eax
			jmp start
			
			
	
		loop1 :
			push ecx; save ecx on stack
			
			lea eax, sequence //prompt for input 
			push eax 
			call printf
			pop eax

			lea eax, seq
			push eax
			lea eax, fmt
			push eax
			call scanf
			add esp, 8

			mov ecx, X
			mov eax, seq//
			cmp eax, 0 


			jg positive
			jl negative
			jz zero

		positive:
			inc pcount
			jmp endif

		negative:
			inc ncount 
			jmp endif

		zero:
			inc zerocount
			jmp endif

		endif:
			pop ecx; restore ecx		
			loop loop1; loop based on ecx

		
		lea eax, poscount
		push eax
		call printf
		pop eax 

		 
		push pcount
		lea eax, fmt
		push eax 
		call printf
		add esp, 8

		lea eax, negcount
		push eax
		call printf
		pop eax

		
		push ncount
		lea eax, fmt 
		push eax 
		call printf
		add esp, 8


		lea eax, zercount
		push eax
		call printf
		pop eax 

		
		push zerocount
		lea eax, fmt 
		push eax
		call printf
		add esp, 8
		
	}

	return 0;
}
//ting code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
