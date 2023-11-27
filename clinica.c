#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 
#include <stdbool.h>

//Registro
struct Consulta {
    char nome[100];
    int dia;
    int hora;
};

//Variáveis Globais
struct Consulta agenda[300];
int qtdAgendamento;

bool verificarDisponibilidade(int diaAgenda, int horaAgenda){
 //sempre retorna true, exceto se for <8, então dá pra agendar às 30:00 horario de brasilia//
    if(horaAgenda < 8){     //if(horaAgenda <8 || >19(horario de fechamento é as 20(...)))
        printf("Clinica Fechada neste horário\n");
        return false;
    } 
    return true;
}

void agendarConsulta(){

    int diaAgenda;
    printf("Qual dia do mês você quer agendar?\n");
    fflush(stdin);
    scanf("%d", &diaAgenda);

    int horaAgenda;
    printf("Qual hora do dia você quer agendar?\n");
    fflush(stdin);
    scanf("%d",&horaAgenda);

    if(verificarDisponibilidade(diaAgenda,horaAgenda)){
        printf("Horário disponível\n");
        printf("Vamos confirmar seu Agendamento\n");
        agenda[qtdAgendamento].dia = diaAgenda;
        agenda[qtdAgendamento].hora = horaAgenda;
        printf("Qual é o seu nome?\n");
        fflush(stdin);
        gets(agenda[qtdAgendamento].nome);
        qtdAgendamento = qtdAgendamento + 1;
        printf("Agendamento Realizado!\n");
    } else {
        printf("Horário não disponível!");
    }
}

void listarConsulta(){
    int i;
    for(i = 0; i < qtdAgendamento; i++){
        printf("========================\n");
        printf("Nome: %s\n", agenda[i].nome);
        printf("Dia: %d\n", agenda[i].dia);
        printf("Hora: %d\n", agenda[i].hora);        
    }
}

void main(){

    setlocale(LC_ALL,"");

    int opcao;
    qtdAgendamento = 0;

    do{
        printf("Deseja uma opção desejada?\n");
        printf("1 - Agendar\n");
        printf("2 - Listar\n");
        printf("3 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 1 :{
                agendarConsulta();
        // break //            
            }case 2 :{
                listarConsulta();
        // break //
            }case 3 :{
                printf("saindo do programa\n");
        // break //
            }
            default :{
                printf("Opção Inválida\n");
            }
        }
    }    while (opcao != 3);
    //return? //
}