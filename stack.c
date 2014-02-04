/* Programa em linguagem c utilizando pilhas, onde o usuario informa o limite para a pilha,vericando se a memória, segue um menu para interagir atrás do teclado onde serão oferecidas cinco opções:inserir,extrair,exibir,consultar e sair do programa, o uduario efetuara um cadastro para aluno,onde poderá estar elimando um determinado ou inserir mais um,através da alocação dinamica.
 
Aluna: Silvana Trindade
data: abril de 2012

*/

#define INSERIR 1
#define EXTRAIR 2
#define EXIBIR 3
#define CONSULTAR 4
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _student {
        char name[40];
        int matriculation;
        int course_code;
}TpAluno;
typedef struct _pilha {
    TpAluno *student;
    int top;
    int limit;
}TpPilha;

TpPilha* criarPilha(int size);
int push(TpPilha* p,TpAluno limit);
int pop ( TpPilha* p,TpAluno valor );
void print(TpPilha* p);
int Top(TpPilha* p);
int empty(TpPilha* p);
int full(TpPilha* p);
void buffer();
void func_free(TpPilha* p);

int main(void)
{
    TpPilha* p_student;
    int limit;//i-para usar o for
    int option,test;
    struct _student top;

    printf("Enter a number of students:");
    scanf("%d",&limit);

    p_student = criarPilha(limit);

    do {

        printf("----MENU----:\n1 inserir dados\n2 extrair\n3 exibir\n4 consultar\n5 sair\n-----------  ");
        scanf("%d",&option);

        
        switch (option) {

            case INSERIR:
		
               // fflush(stdout);
               // fflush(stdin);
               printf("%d\n", p_student->top); //Impressão do valor do topo neste momento
		           printf("%d\n",p_student->limit);//Impressão do valor do limite
				if(full(p_student)) {

					printf("\nERROR...");

				}
				else {
				        //for (i = 0; i <= p_aluno->limite; i++) { usar caso queira que o usuario ensira todos os elementos
					TpAluno student;

				    printf("name:");
					buffer();
				    fgets(student.name,40,stdin);
					test = strlen (student.name);
	 				if (student.name[test -1] == '\n') {

						student.name[test -1] = '\0';

		        	 }
		         	/*fflush(stdout);
		        	 _fpurge(stdin);
			   		*/
		         	printf("matriculation:");
		         	scanf("%d",&student.matriculation);

		         	printf("course code:");
		         	scanf("%d",&student.course_code);

		         	buffer();

		        	push(p_student,student);
		         }
		         break;

            case EXTRAIR:
				
                Top(p_student);

                if((pop(p_student,top))==1) {

            		printf("SUCESS\n");
				}
				else {
					printf("ERROR\n");
				}
				
                break;

            case EXIBIR:

                print(p_student);

                break;

            case CONSULTAR:{

                TpAluno al = p_student->student[Top(p_student)];

                printf("name:%s\n",al.name);
                printf("matriculation:%d\n",al.matriculation);
                printf("course code:%d\n",al.course_code);

                break;
        	}
            default:
                break;
        }
    } while (option != 5);

        func_free(p_student);
        
		return 0;
}

TpPilha* criarPilha (int size) {

    TpPilha* p;
    p = (TpPilha*) malloc (sizeof (TpPilha));

    if ( p ) {

        p->student = (TpAluno*) calloc (size,sizeof(TpAluno) );
        //"Memória alocada com sucesso.

    }
    else {

        printf("Error:not enough memory...\n");

    }
    if( p->student ) {

        p->top=-1;
        p->limit = size -1;
        return p;

    }
    else {

        return NULL;

    }
}
int push(TpPilha* p,TpAluno limit) {//inserir elementos a função

    if (p->top < p->limit) {
            p->top += 1;
            p->student[p->top] = limit;

            return 1;
    }
    else {
            return 0;
    }
}
int pop ( TpPilha* p,TpAluno value ) {//extrair elemento do topo da pilha
	if ( p->top > 0 ) {

        p->top -= 1;
        value = p->student[p->top];

        return 1;
    }
    else if ( p->top == 0 ) {
        return 0;
    }
    else {

        return 0;

    }
  
}

int empty ( TpPilha* p ) {//verifica se esta vazia

    return ( p->top < 0 );
}

int full (TpPilha* p) {//verifica se esta cheia

    return (p->top == p->limit);
}

void print (TpPilha *p) {//imprime o que esta na pilha
    int i;

    if (empty(p)) {
            return;
     }

    for ( i = 0; i <= p->top; i++ ) {

		printf("\nname : %s\n", p->student[i].name);
		printf("matriculation : %d\n", p->student[i].matriculation);
		printf("course_code : %d\n\n", p->student[i].course_code);

   }
 }
int Top ( TpPilha* p ) {//retorna o topo

    if (empty (p)) {
	
    }
    else {

        return p->top;
    }
	return 0;
}
void buffer () { //limpara buffer da função fgets

    char garbage ='\0';

    while((garbage = getchar()) && garbage !='\n' && garbage!=EOF ) {
        return;
    }
}
void func_free(TpPilha* p) {//libera memória

	free(p->student);
	free(p);
}
