#include <stdio.h>
#include <stdlib.h>

//struct responsavel pelo telefone
struct Phone{
    int number;
    struct Phone *next;
};
typedef struct Phone phone;

//struct responsavel pelo email
struct Email{
    char email[30];
    struct Email *next;
};
typedef struct Email email;

//struct responsavel pela agenda
struct Shedule{
    char name[30];
    char adress[30];
    phone *phone;
    email *email;
    struct Shedule *next;
};
typedef struct Shedule shedule;

//tamanho da lista
int size;

//alocar novo nó email
void *AllocateEmail(email *LIST){
    char option;
    do{
        email *newRegister = (email *)malloc(sizeof(email));
        printf("Digite o email: ");
        scanf("%s",&newRegister->email);
        newRegister->next=NULL;

        if(LIST->next==NULL){
            LIST->next=newRegister;
        }else{
            email *temp = LIST->next;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newRegister;
        }
        printf("Deseja cadastrar outro email?[S/N]\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%c",&option);
        fflush(stdin);
    }while(option!='n');
}

//alocar novo nó agenda
//(Aqui é um nó 'livre'... sem vinculo com nenhuma lista)
shedule *AllocateShedule(){
    shedule *newRegister = (shedule *)malloc(sizeof(shedule));
    email *newEmail = (email*)malloc(sizeof(email));

    if(!newRegister){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        printf("Digite o nome: ");
        scanf("%s",&newRegister->name);

        printf("Digite o endereco: ");
        scanf("%s",&newRegister->adress);

        //alocando um email e apontando para o novo registro da agenda
        AllocateEmail(newEmail);

        newRegister->email=newEmail;
        return newRegister;
    }
}



//alocar novo nó telefone
phone AllocatePhone(shedule *LIST){

}

//struct para iniciar a agenda
void StartShedule(shedule *LIST){

}



//inserir no inicio da lista agenda
void InsertStartShedule(shedule *LIST){
    shedule *newRegister = AllocateShedule();
    shedule *oldHead = LIST->next;

    LIST->next = newRegister;
    newRegister->next=oldHead;
    size++;
}

//inserir no fim da lista agenda
void InsertEndShedule(shedule *LIST){

}

//inserir na posição desejada da lista agenda
void InsertChooseShedule(shedule *LIST){

}

//inserir novo email
void InsertEmail(shedule *LIST){

}

//inserir novo telefone
void InsertPhone(shedule *LIST){

}

//mostrar todos os emails da lista agenda
void ShowAllEmail(email *LIST){
    email *tempRegister;
    int cont=0;

    tempRegister=LIST->next;
    while(tempRegister!=NULL){
        cont++;
        printf("email-%d%s\n",cont,tempRegister->email);
        tempRegister=tempRegister->next;
    }
}

//mostrar a lista agenda
void ShowAllSchedule(shedule *LIST){
    shedule *tempRegister;

    tempRegister=LIST->next;

    while(tempRegister!=NULL){
        printf("Nome: %s\n",tempRegister->name);
        printf("Endereco: %s\n",tempRegister->adress);
        ShowAllEmail(tempRegister->email);
        tempRegister=tempRegister->next;
    }

}


//mostrar todos os telefones da lista agenda
void ShowAllPhone(shedule *LIST){}


//zerar as listas
void ClearAll(shedule *LIST){

}



//verificar se a lista agenda está vazia
void GetEmptyShedule(shedule *LIST){

}

//verificar se a lista de email está vazia
void GetEmptyEmail(shedule *LIST){

}

//verificar se a lista de telefone está vazia
void GetEmptyPhone(shedule *LIST){

}

void menu(shedule *LIST){
    int option;

    do{
        printf("0-Exibir lista\n");
        printf("1-Inserir no inicio\n");
        printf("2-Inserir no final\n");
        printf("3-Escolher onde inserir\n");
        printf("4-Retirar do inicio\n");
        printf("5-Retirar do final\n");
        printf("6-Escolher onde retirar\n");
        printf("7-Zerar lista\n");
        printf("8-Sair\n");
        printf("Digite a opcao: ");
        scanf("%d",&option);


        switch(option){
            case 0:
                ShowAllSchedule(LIST);
                break;
            case 1:
                InsertStartShedule(LIST);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                system("exit");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }

    }while(option!=8);
}

int main()
{
    shedule *LIST=(shedule *)malloc(sizeof(shedule));
    StartShedule(LIST);
    menu(LIST);
    return 0;
}
