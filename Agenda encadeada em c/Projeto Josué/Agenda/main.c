#include <stdio.h>
#include <stdlib.h>

//struct responsavel pelo telefone
struct Phone{
    char number[12];
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
//verifica se a lista ta vazia
int vazia(shedule *LIST){
    if(LIST->next ==NULL){
        return 1;
    }else
        return 0;
}
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
        scanf("%s",&option);
        fflush(stdin);
    }while(option!=110);
}
//alocar novo nó telefone
void *AllocatePhone(phone *LIST){
    char option;
    do{
        phone *newRegister = (phone *)malloc(sizeof(phone));
        printf("Digite o telefone: ");
        scanf("%s", &newRegister->number);
        newRegister->next=NULL;

        if(LIST->next==NULL){
            LIST->next=newRegister;
        }else{
            phone *temp = LIST->next;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newRegister;
        }
        printf("Deseja cadastrar outro telefone?[S/N]\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%s",&option);
        fflush(stdin);
    }while(option!=110);
}

//alocar novo nó agenda
//(Aqui é um nó 'livre'... sem vinculo com nenhuma lista)
shedule *AllocateShedule(){
    shedule *newRegister = (shedule *)malloc(sizeof(shedule));
    email *newEmail = (email*)malloc(sizeof(email));
    phone *newPhone = (phone*)malloc(sizeof(phone));

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
        //alocando telefone    ^^^
        AllocatePhone(newPhone);

        newRegister->email=newEmail;
        newRegister->phone=newPhone;
        return newRegister;
    }
}

//struct para iniciar a agenda
void StartShedule(shedule *LIST){
    LIST-> next=NULL;
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
    shedule *newRegister = AllocateShedule();
    shedule *temp = LIST->next;
    if(vazia(LIST)){
        LIST->next = newRegister;
    }else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newRegister;
    }
    
}
//mostrar todos os emails da lista agenda
void ShowAllEmail(email *LIST){
    email *tempRegister;
    int cont=0;

    tempRegister=LIST->next;
    while(tempRegister!=NULL){
        cont++;
        printf("Email - %d %s\n",cont,tempRegister->email);
        tempRegister=tempRegister->next;
    }
}
//mostrar todos os telefones da lista agenda
void ShowAllPhone(phone *LIST){
    phone *tempRegister;
    int cont=0;

    tempRegister=LIST->next;
    while(tempRegister!=NULL){
        cont++;
        printf("Telefone - %d %s\n",cont,tempRegister->number);
        tempRegister=tempRegister->next;
    }
}

//mostrar a lista agenda
void ShowAllSchedule(shedule *LIST){
    shedule *tempRegister;
    int id=0;

    tempRegister=LIST->next;

    while(tempRegister!=NULL){
        id++;
        printf("ID:%d\n", id);
        printf("Nome: %s\n",tempRegister->name);
        printf("Endereco: %s\n",tempRegister->adress);
        ShowAllEmail(tempRegister->email);
        ShowAllPhone(tempRegister->phone);
        printf("\n");
        tempRegister=tempRegister->next;
    }
    printf("\n");
}
//inserir na posição desejada da lista agenda
void InsertChooseShedule(shedule *LIST){
  int pos,count;
  ShowAllSchedule(LIST);
  printf("Em que posicao voce deseja inserir: \n");
  scanf("%d", &pos);

  if(pos>0){
    if(pos==1)
      InsertStartShedule(LIST);
    else{
      shedule *atual = LIST->next,*anterior=LIST; 
      shedule *novo=AllocateShedule();

      for(count=1 ; count < pos ; count++){
        anterior=atual;
        atual=atual->next;
        if(atual == NULL){
            printf("Opcao de id invalida");
            break;
        }
      }
      anterior->next=novo;
      novo->next = atual;
      }

      }else
        printf("Elemento invalido\n\n");  
}
//pesquisa o id do cadastro a ser matriculado
int searchMatch(shedule *LIST){
    system("clear");
    ShowAllSchedule(LIST);
    printf("Indique o id do qual sera adicionado:\n");
    int id;
    scanf("%d", &id);
    int idList = 0;
    shedule *tmp;
    tmp = LIST->next;
    while(tmp->next!=NULL && idList < id){
        if(idList == id){
            break;
        }
        else
            tmp = tmp->next;

        idList++;
    }
    return id-1;
}
//adicionar mais um email
void emailPlus(shedule *LIST){
    email *newEmail = (email*)malloc(sizeof(email));
    shedule *tmp;
    tmp = LIST->next;
    int id = searchMatch(LIST);
    for(int i =0;i<id;i++){
        tmp = tmp->next;
    }
    AllocateEmail(tmp->email);
}
//adicionar mais um telefone
void phonePlus(shedule *LIST){
    phone *newPhone = (phone*)malloc(sizeof(phone));
    shedule *tmp;
    tmp = LIST->next;
    int id = searchMatch(LIST);
    for(int i =0;i<id;i++){
        tmp = tmp->next;
    }
    AllocatePhone(tmp->phone);
}
//remove nó do inicio
void StartRemove(shedule *LIST){
  if(LIST->next == NULL){
    printf("Lista ja esta vazia\n");
  }else{
    shedule *tmp = LIST->next;
    LIST->next = tmp->next;
  }
}
//remove nó do final
void EndRemove(shedule *LIST){
  if(LIST->next == NULL){
    printf("Lista ja vazia\n\n");
  }else{
    shedule *ultimo = LIST->next,
    *penultimo = LIST;
    while(ultimo->next != NULL){
        penultimo = ultimo;
        ultimo = ultimo->next;
    }
    penultimo->next= NULL;
  }
}
//remove nó de um ponto especifico
void SpecificRemove(shedule *LIST){
    int opt;
    int count = 0;
    ShowAllSchedule(LIST);
    printf("Que posicao voce deseja retirar?\n ");
    scanf("%d", &opt);

    if(opt>0){
        if(opt==1)
            StartRemove(LIST);
        else{
            shedule *atual = LIST->next,*anterior=LIST; 

            for(count=1 ; count < opt ; count++){
                anterior=atual;
                atual=atual->next;
                if(atual == NULL){
                    printf("Opcao de id invalida");
                    break;
                }
            }
            anterior->next=atual->next;
        }
    }else{
    printf("Elemento invalido\n\n");    
    }
}
//limpar registros email
void ClearEmail(email *LIST){
    email *prox,*atual;
    atual = LIST->next;
    while(atual!=NULL){
        prox = atual->next;
        free(atual);
        atual = prox;
    } 
}
//limpar telefone
void ClearPhone(phone *LIST){
    phone *prox,*atual;
    atual = LIST->next;
    while(atual!=NULL){
        prox = atual->next;
        free(atual);
        atual = prox;
    }
}
//limpar nomes
void ClearName(shedule *LIST){
    shedule *prox,*atual;
    atual = LIST->next;
    while(atual!=NULL){
        prox = atual->next;
        free(atual);
        atual = prox;
    }
}
//zerar as listas
void ClearAll(shedule *LIST){
    shedule *tmp = LIST->next;
    //ClearAddr(LIST);
    while(tmp!=NULL){
        ClearEmail(tmp->email);
        ClearPhone(tmp->phone);
        ClearName(LIST);
        //ClearAddr(LIST);
        tmp=tmp->next;
    }
}

//verificar se a lista de email está vazia
void GetEmptyEmail(shedule *LIST){

}

//verificar se a lista de telefone está vazia
void GetEmptyPhone(shedule *LIST){

}

void menu(shedule *LIST){
    int option,id;

    do{
        printf("0-Exibir lista\n");
        printf("1-Inserir no inicio\n");
        printf("2-Inserir no final\n");
        printf("3-Inserir email em um cadastro ja existente\n");
        printf("4-Inserir telefone em um cadastro ja existente\n");
        printf("5-Inserir em um local especifico\n");
        printf("6-Retirar do inicio\n");
        printf("7-Retirar do final\n");
        printf("8-Escolher onde retirar\n");
        printf("9-Zerar lista\n");
        printf("10-Sair\n");
        printf("Digite a opcao: ");
        scanf("%d",&option);


        switch(option){
            case 0:
                system("clear");
                ShowAllSchedule(LIST);
                break;
            case 1:
                InsertStartShedule(LIST);
                break;
            case 2:
                InsertEndShedule(LIST);
                break;
            case 3:
                emailPlus(LIST);
                break;
            case 4:
                phonePlus(LIST);
                break;
            case 5:
                InsertChooseShedule(LIST);
                break;
            case 6:
                StartRemove(LIST);
                break;
            case 7:
                EndRemove(LIST);
                break;
            case 8:
                SpecificRemove(LIST);
                break;
            case 9:
                ClearAll(LIST);
                StartShedule(LIST);
                break;
            case 10:
                system("exit");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }

    }while(option!=9);
}

int main()
{
    shedule *LIST=(shedule *)malloc(sizeof(shedule));
    StartShedule(LIST);
    menu(LIST);
    return 0;
}
