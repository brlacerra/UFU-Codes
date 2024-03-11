#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    int op;
    char treinoPeito[10][100] = {"Supino Inclinado com Barra", "Supino Reto", "Hammer ou Articulado ", " Supino com Halteres ", " Crucifixo no Aparelho ", "Crucifixo Reto com Halteres", "Cross Over (Para Peitoral Inferior)", "Cross Over com Polia Baixa ", " Supino Fechado ", " Supino Reto Com Barra "};
    char treinoTriceps[10][100] = {"Extensao de Triceps com Barra", "Pulldown na Maquina ", " Triceps Testa com Halteres ", " Triceps Coice ", " Mergulhos em Paralelas ", " Extensao de Triceps com Corda ", " Triceps na Polia Alta ", " Triceps no Banco ", " Flexao de Bracos Diamante ", " Triceps Kickback "};
    char treinoCosta[10][100] = {"Levantamento Terra", "Puxada na Frente", "Remada Curvada", "Pull-Up", "Maquina de Pulldown", "Remada Unilateral", "Hiperextensao", "Puxada Alta", "Puxada Baixa", "Barra Fixa"};
    char treinoBiceps[10][100] = {"Rosca Direta", "Martelo", "21s", "Rosca Concentrada ", " Rosca Scott ", " Rosca Inversa ", " Rosca 21 ", " Rosca Alternada ", "Rosca com Barra Z", "Rosca 21s Invertida"};
    char treinoOmbro[10][100] = {"Desenvolvimento Militar", "Elevacao Lateral", "Elevacao Frontal", "Elevacao Posterior", "Press Arnold", "Remada Alta", "Encolhimento de Ombros", "Elevacao Frontal com Halteres", "Elevacao Lateral com Halteres ", " Elevacao com Cabo "};
    char treinoAntebraco[10][100] = {"Rosca de Punho com Barra", "Rosca de Punho com Halteres ", " Flexao de Punho com Barra ", " Flexao de Punho com Halteres ", " Rosca Invertida com Barra ", " Rosca Invertida com Halteres ", " Rosca de Punho com Corda ", " Pronacao de Punho ", " Supinacao de Punho ", " Extensao de Punho "};
    char treinoPerna[10][100] = {"Agachamento Livre", "Leg Press", "Cadeira Extensora ", " Levantamento Terra ", " Cadeira Flexora ", " Avanco com Barra ", "Agachamento Smith", "Agachamento Bulgaro", "Prensa 45 Graus"};
    char semana[5][50] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    char treinos[8][20] = {"Peito", "Triceps", "Costa", "Biceps", "Ombro",
                           "Antebraco", "Perna", "Nenhum"};
    struct cliente
    {
        int codigo;
        char nome[100];
        int idade;
        float peso;
        float altura;
        float precoMens;
        char sexo;
        int rot = 0;
    };
    struct rotina
    {
        int codigo;
        int codCliente;
        int segunda[6];
        int terca[6];
        int quarta[6];
        int quinta[6];
        int sexta[6];
        int ordem[5][2];
    };
    typedef cliente cliente;
    typedef rotina rotina;
    cliente cl[12];
    rotina rot[12];
    int codCliente = 0, qtdCliente = 0, idex = 0;
    int codRotina = 0, qtdRotina = 0;
    int sexdif = 0, nomeIgual = 0;
    do
    {
        system("cls");
        printf("-->MENU ACADEMIA<--\n\n");
        printf("Digite a opcao desejada, de acordo com o menu abaixo:\n");
        printf("1-Cadastrar Cliente\n2-Alterar Cliente\n3-Listar Cliente\n4-Cadastrar Rotina de treino\n5-Consultar Rotina de Treino\n6-Excluir Cliente\n7-Excluir primeiro cliente Cadastrado\n0-Sair\n");
        printf("OPCAO: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            char esc[3];
            printf("-->CADASTRAR CLIENTE<--\n\n");
            printf("Voce escolheu CADASTRAR CLIENTE, deseja prosseguir com a operacao? ");
            fflush(stdin);
            gets(esc);
            strlwr(esc);
            if (strcmp(esc, "sim") == 0)
            {
                system("cls");
                printf("-->CADASTRAR CLIENTE<--\n\n");
                cl[qtdCliente].codigo = codCliente;
                do
                {
                    nomeIgual = 0;
                    printf("Digite o nome do cliente: ");
                    fflush(stdin);
                    gets(cl[qtdCliente].nome);
                    for (int i = 0; i < qtdCliente; i++)
                    {
                        if (strcmp(cl[qtdCliente].nome, cl[i].nome) == 0)
                        {
                            nomeIgual++;
                        }
                    }
                    if (nomeIgual > 0)
                    {
                        printf("Nome ja existente. ");
                    }
                } while (nomeIgual > 0);
                printf("Digite a idade do cliente: ");
                scanf("%d", &cl[qtdCliente].idade);
                printf("Digite o peso do cliente: ");
                scanf("%f", &cl[qtdCliente].peso);
                printf("Digite a altura do cliente: ");
                scanf("%f", &cl[qtdCliente].altura);
                do
                {
                    sexdif = 0;
                    printf("Digite o sexo da pessoa, sendo:\nM-Masculino\nFFeminino:\nOPCAO: ");
                    fflush(stdin);
                    scanf("%c", &cl[qtdCliente].sexo);
                    if (cl[qtdCliente].sexo != 'M' && cl[qtdCliente].sexo != 'F')
                    {
                        sexdif = 1;
                        printf("Opcao de sexo invalida. ");
                    }
                } while (sexdif == 1);
                printf("Digite o preco da mensalidade do cliente: ");
                scanf("%f", &cl[qtdCliente].precoMens);
                cl[qtdCliente].rot = 0;
                system("cls");
                printf("-->CADASTRAR CLIENTE<--\n\n");
                printf("Cliente cadastrado com sucesso!\n");
                qtdCliente++;
                codCliente++;
            }
            else
            {
                system("cls");
                printf("-->CADASTRAR CLIENTE<--\n\n");
                printf("Voce negou a operacao!\n");
            }
            printf("Pressione ENTER para continuar.");
            fflush(stdin);
            getchar();
            break;
        case 2:
            char esc2[3];
            system("cls");
            printf("-->ALTERAR CLIENTE<--\n\n");
            printf("Voce escolheu ALTERAR CLIENTE, deseja prosseguir com a operacao? ");
            fflush(stdin);
            gets(esc2);
            strlwr(esc2);
            if (strcmp(esc2, "sim") == 0)
            {
                system("cls");
                if (qtdCliente > 0)
                {
                    do
                    {
                        system("cls");
                        printf("-->ALTERAR CLIENTE<--\n\n");
                        for (int i = 0; i < qtdCliente; i++)
                        {
                            printf("CLIENTE ID: %04d\n", cl[i].codigo);
                            printf("Nome: %s\n", cl[i].nome);
                            printf("\n\n");
                        }
                        int idalt;
                        idex = 0;
                        printf("Digite o ID do cliente que deseja alterar: ");
                        scanf("%d", &idalt);
                        for (int i = 0; i < qtdCliente && idex == 0; i++)
                        {
                            if (idalt == cl[i].codigo)
                            {
                                idex = 1;
                            }
                        }
                        if (idex == 1)
                        {
                            system("cls");
                            printf("--ALTERAR CLIENTE/ID: %04d<--\n\n", idalt);
                            for (int i = 0; i < qtdCliente; i++)
                            {
                                if (cl[i].codigo == idalt)
                                {
                                    printf("Digite qual informacao deseja alterar no cliente:\n");
                                    printf("1-Nome\n2-Idade\n3-Peso\n4-Altura\n5- Sexo\n6-Preco de Mensalidade\nOPCAO: ");
                                    int opalt;
                                    scanf("%d", &opalt);
                                    switch (opalt)
                                    {
                                    case 1:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("O atual nome do cliente e: %s\n",
                                               cl[i].nome);
                                        do
                                        {
                                            nomeIgual = 0;
                                            printf("Digite o novo nome do cliente: ");
                                            fflush(stdin);
                                            gets(cl[i].nome);
                                            for (int ii = 0; ii < qtdCliente; ii++)
                                            {
                                                if (strcmp(cl[ii].nome, cl[i].nome) == 0)
                                                {
                                                    if (cl[ii].codigo != cl[i].codigo)
                                                    {
                                                        nomeIgual++;
                                                    }
                                                }
                                            }
                                            if (nomeIgual > 0)
                                            {
                                                printf("Nome ja existente. ");
                                            }
                                        } while (nomeIgual > 0);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Nome alterado com sucesso!\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("A atual idade do cliente e: %d\n",
                                               cl[i].idade);
                                        printf("Digite a nova idade do cliente: ");
                                        scanf("%d", &cl[i].idade);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Idade alterada com sucesso!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("O atual peso do cliente e: %.1f\n",
                                               cl[i].peso);
                                        printf("Digite o novo peso do cliente: ");
                                        scanf("%f", &cl[i].peso);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Peso alterado com sucesso!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("A altura atual do cliente e: %.2f\n",
                                               cl[i].altura);
                                        printf("Digite a nova altura do cliente: ");
                                        scanf("%f", &cl[i].altura);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Altura alterada com sucesso!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("O sexo atual do cliente e: ");
                                        if (cl[i].sexo == 'M')
                                        {
                                            printf("Masculino\n");
                                        }
                                        else
                                        {
                                            printf("Feminino\n");
                                        }
                                        do
                                        {
                                            sexdif = 0;
                                            printf("Digite o novo sexo da pessoa, sendo:\nM-Masculino\nF-Feminino:\nOPCAO: ");
                                            fflush(stdin);
                                            scanf("%c", &cl[qtdCliente].sexo);
                                            if (cl[qtdCliente].sexo != 'M' &&
                                                cl[qtdCliente].sexo != 'F')
                                            {
                                                sexdif = 1;
                                                printf("Opcao de sexo invalida. ");
                                            }
                                        } while (sexdif == 1);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Sexo alterado com sucesso!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("O preco atual da mensalidade do cliente e de: R$%.2f\n", cl[i].precoMens);
                                        printf("Digite o novo valor da mensalidade do cliente: ");
                                        scanf("%f", &cl[i].precoMens);
                                        system("cls");
                                        printf("--ALTERAR CLIENTE/ID: %04d<--\n\n",
                                               cl[i].codigo);
                                        printf("Altura alterada com sucesso!\n");
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            system("cls");
                            printf("-->ALTERAR CLIENTE<--\n\n");
                            printf("ID selecinado nao corresponde a um id existente!\n");
                            printf("Deseja tentar novamente? ");
                            char esc3[3];
                            fflush(stdin);
                            gets(esc3);
                            strlwr(esc3);
                            if (strcmp(esc3, "sim") != 0)
                            {
                                idex = 1;
                            }
                        }
                    } while (idex == 0);
                }
                else
                {
                    system("cls");
                    printf("-->ALTERAR CLIENTE<--\n\n");
                    printf("Nao existe nenhum cliente cadastrado para realizar a alteracao de dados!\n");
                }
            }
            else
            {
                printf("Voce cancelou a operacao!\n");
            }
            printf("Pressione ENTER para continuar.");
            fflush(stdin);
            getchar();
            break;
        case 3:
            system("cls");
            printf("-->LISTAR CLIENTES<--\n\n");
            if (qtdCliente > 0)
            {
                for (int i = 0; i < qtdCliente; i++)
                {
                    printf("CLIENTE ID: %04d\n", cl[i].codigo);
                    printf("Nome: %s\n", cl[i].nome);
                    printf("Idade: %d\n", cl[i].idade);
                    printf("Peso: %.1f\n", cl[i].peso);
                    printf("Altura: %.2f\n", cl[i].altura);
                    printf("Sexo: ");
                    if (cl[i].sexo == 'M')
                    {
                        printf("Masculino\n");
                    }
                    else
                    {
                        printf("Feminino\n");
                    }
                    printf("Preco da mensalidade: R$%.2f", cl[i].precoMens);
                    printf("\n\n");
                }
            }
            else
            {
                printf("Nao ha registro de clientes para listar!\n");
            }
            printf("Pressione ENTER para continuar.");
            fflush(stdin);
            getchar();
            break;
        case 4:
            char esc4[3];
            system("cls");
            printf("-->CADASTRAR ROTINA DE TREINO<--\n\n");
            printf("Voce escolheu CADASTRAR ROTINA DE TREINO, deseja prosseguir com a operacao? ");
            fflush(stdin);
            gets(esc4);
            strlwr(esc4);
            if (strcmp(esc4, "sim") == 0)
            {
                system("cls");
                printf("-->CADASTRAR ROTINA DE TREINO<--\n\n");
                if (qtdCliente > 0)
                {
                    do
                    {
                        system("cls");
                        printf("-->CADASTRAR ROTINA DE TREINO<--\n\n");
                        for (int i = 0; i < qtdCliente; i++)
                        {
                            printf("CLIENTE ID: %04d\n", cl[i].codigo);
                            printf("Nome: %s\n", cl[i].nome);
                            printf("\n\n");
                        }
                        int idalt;
                        idex = 0;
                        printf("Digite o ID do cliente que deseja cadastrar uma rotina de treino: ");
                        scanf("%d", &idalt);
                        for (int i = 0; i < qtdCliente; i++)
                        {
                            if (idalt == cl[i].codigo)
                            {
                                idex = 1;
                            }
                        }
                        if (idex == 1)
                        {
                            system("cls");
                            printf("-->CADASTRAR ROTINA DE TREINO/ID: %04d<--\n\n", idalt);
                            for (int i = 0; i < qtdCliente; i++)
                            {
                                if (idalt == cl[i].codigo)
                                {
                                    if (cl[i].rot == 0)
                                    {
                                        for (int ii = 0; ii < 5; ii++)
                                        {
                                            system("cls");
                                            printf("-->CADASTRAR ROTINA DE TREINO/ID: %04d<--\n\n", cl[i].codigo);
                                            rot[qtdRotina].codCliente = cl[i].codigo;
                                            rot[qtdRotina].codigo = codRotina;
                                            printf("Digite o treino que voce deseja cadastrar para %s:\n", semana[ii]);
                                            for (int i2 = 0; i2 < 8; i2++)
                                            {
                                                printf("%d - %s\n", i2, treinos[i2]);
                                            }
                                            printf("OPCAO 1: ");
                                            scanf("%d", &rot[qtdRotina].ordem[ii][0]);
                                            printf("OPCAO 2: ");
                                            scanf("%d", &rot[qtdRotina].ordem[ii][1]);
                                        }
                                        for (int ii = 0; ii < 5; ii++)
                                        {
                                            int rep = 0;
                                            for (int i2 = 0; i2 < 2; i2++)
                                            {
                                                int i3 = 0, lim = 3;
                                                if (rep == 1)
                                                {
                                                    i3 = 3;
                                                    lim = 6;
                                                }
                                                else
                                                {
                                                    i3 = 0;
                                                    lim = 3;
                                                }
                                                system("cls");
                                                printf("-->CADASTRAR ROTINA DE TREINO/ID: %04d/%s<--\n\n", cl[i].codigo, semana[ii]);
                                                switch (rot[qtdRotina].ordem[ii][i2])
                                                {
                                                case 0:
                                                    printf("Selecione 3 treinos para peito:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoPeito[i3]);
                                                    }
                                                    break;
                                                case 1:
                                                    printf("Selecione 3 treinos para Triceps:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoTriceps[i3]);
                                                    }
                                                    break;
                                                case 2:
                                                    printf("Selecione 3 treinos para Costa:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoCosta[i3]);
                                                    }
                                                    break;
                                                case 3:
                                                    printf("Selecione 3 treinos para Biceps:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoBiceps[i3]);
                                                    }
                                                    break;
                                                case 4:
                                                    printf("Selecione 3 treinos para Ombro:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoOmbro[i3]);
                                                    }
                                                    break;
                                                case 5:
                                                    printf("Selecione 3 treinos para Antebraco:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3,
                                                               treinoAntebraco[i3]);
                                                    }
                                                    break;
                                                case 6:
                                                    printf("Selecione 3 treinos para Perna:\n");
                                                    for (int i3 = 0; i3 < 10; i3++)
                                                    {
                                                        printf("%d - %s\n", i3, treinoPerna[i3]);
                                                    }
                                                    break;
                                                }
                                                if (rot[qtdRotina].ordem[ii][i2] != 7)
                                                {
                                                    for (i3 = i3; i3 < lim; i3++)
                                                    {
                                                        printf("OPCAO %d: ", i3 + 1);
                                                        switch (ii)
                                                        {
                                                        case 0:
                                                            scanf("%d",
                                                                  &rot[qtdRotina].segunda[i3]);
                                                            break;
                                                        case 1:
                                                            scanf("%d", &rot[qtdRotina].terca[i3]);
                                                            break;
                                                        case 2:
                                                            scanf("%d",
                                                                  &rot[qtdRotina].quarta[i3]);
                                                            break;
                                                        case 3:
                                                            scanf("%d",
                                                                  &rot[qtdRotina].quinta[i3]);
                                                            break;
                                                        case 4:
                                                            scanf("%d",
                                                                  &rot[qtdRotina].sexta[i3]);
                                                            break;
                                                        }
                                                    }
                                                }
                                                rep++;
                                            }
                                        }
                                        cl[i].rot = 1;
                                        system("cls");
                                        printf("-->CADASTRAR ROTINA DE TREINO<-- \n\n");
printf("Rotina de Treino cadastrada com sucesso!\n");
qtdRotina++;
codRotina++;
getchar();
                                    }
                                    else
                                    {
                                        printf("O Cliente ja possui uma rotina cadastrada!\n");
                                    }
                                }
                            }
                        }
                        else
                        {
                            system("cls");
                            printf("-->CADASTRAR ROTINA DE TREINO<--\n\n");
                            printf("ID selecinado nao corresponde a um id existente!\n");
                            printf("Deseja tentar novamente? ");
                            char esc5[3];
                            fflush(stdin);
                            gets(esc5);
                            strlwr(esc5);
                            if (strcmp(esc5, "sim") != 0)
                            {
                                idex = 1;
                            }
                        }
                    } while (idex == 0);
                }
                else
                {
                    printf("Ainda nao existem registros de clientes para ser criado uma rotina de treino!\n");
                }
                printf("Pressione ENTER para continuar");
                fflush(stdin);
                getchar();
            }
            else
            {
                printf("Voce negou a operacao!\n");
                printf("Pressione ENTER para continuar");
                fflush(stdin);
                getchar();
            }
            break;
        case 5:
            char esc6[3];
            system("cls");
            printf("-->CONSULTAR ROTINA DE TREINO<--\n\n");
            printf("Voce escolheu CONSULTAR ROTINA DE TREINO, deseja prosseguir com a operacao? ");
            fflush(stdin);
            gets(esc6);
            strlwr(esc6);
            system("cls");
            printf("-->CONSULTAR ROTINA DE TREINO<--\n\n");
            if (strcmp(esc6, "sim") == 0)
            {
                if (qtdRotina > 0)
                {
                    do
                    {
                        system("cls");
                        printf("-->CONSULTAR ROTINA DE TREINO<--\n\n");
                        for (int i = 0; i < qtdRotina; i++)
                        {
                            printf("ROTINA ID: %04d\n", rot[i].codigo);
                            for (int ii = 0; ii < qtdCliente; ii++)
                            {
                                if (rot[i].codCliente == cl[ii].codigo)
                                {
                                    printf("COD.cliente: %04d Nome: %s\n", cl[ii].codigo,
                                           cl[ii].nome);
                                }
                            }
                            printf("\n\n");
                        }
                        int idalt;
                        int opBusca;
                        idex = 0;
                        do
                        {
                            idalt = 999;
                            opBusca = 0;
                            printf("Deseja buscar uma rotina de treino pelo codigo da rotina ou pelo nome do Cliente?:\n1-Codigo\n2-Nome do Cliente\nOPCAO: ");
                            scanf("%d", &opBusca);
                            if (opBusca == 1)
                            {
                                printf("Digite o codigo da rotina que deseja consultar: ");
                                scanf("%d", &idalt);
                            }
                            else if (opBusca == 2)
                            {
                                printf("Digite o nome do Cliente no qual deseja consultar a rotina de treino: ");
                                char nomeCons[100];
                                fflush(stdin);
                                gets(nomeCons);
                                for (int i = 0; i < qtdCliente; i++)
                                {
                                    if (strcmp(nomeCons, cl[i].nome) == 0)
                                    {
                                        idalt = cl[i].codigo;
                                    }
                                }
                            }
                            else
                            {
                                printf("Opcao inexistente. ");
                            }
                        } while (opBusca < 1 || opBusca > 2);
                        for (int i = 0; i < qtdRotina; i++)
                        {
                            if (idalt == rot[i].codigo)
                            {
                                idex = 1;
                            }
                        }
                        if (idex == 1)
                        {
                            for (int i = 0; i < qtdRotina; i++)
                            {
                                if (rot[i].codigo == idalt)
                                {
                                    for (int ii = 0; ii < qtdCliente; ii++)
                                    {
                                        if (rot[i].codCliente == cl[ii].codigo)
                                        {
                                            system("cls");
                                            printf("-->CONSULTAR ROTINA DO CLIENTE<--\n\n");
                                            printf("ID do Cliente: %04d\n", cl[ii].codigo);
                                            printf("Nome do Cliente: %s\n", cl[ii].nome);
                                            printf("Peso: %.2f Idade: %d Sexo: ",
                                                   cl[ii].peso, cl[ii].idade);
                                            if (cl[ii].sexo == 'M')
                                            {
                                                printf("Masculino\n");
                                            }
                                            else
                                            {
                                                printf("Feminino\n");
                                            }
                                            printf("ID da Rotina de Treino: %04d\n\n",
                                                   rot[i].codigo);
                                            for (int i2 = 0; i2 < 5; i2++)
                                            {
                                                printf("%s:\n", semana[i2]);
                                                int rep = 0;
                                                for (int i3 = 0; i3 < 2; i3++)
                                                {
                                                    int i4, lim;
                                                    if (rep == 1)
                                                    {
                                                        i4 = 3;
                                                        lim = 6;
                                                    }
                                                    else
                                                    {
                                                        i4 = 0;
                                                        lim = 3;
                                                    }
                                                    for (i4 = i4; i4 < lim; i4++)
                                                    {
                                                        switch (rot[i].ordem[i2][i3])
                                                        {
                                                        case 0:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPeito[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPeito[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPeito[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPeito[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPeito[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 1:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoTriceps[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoTriceps[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoTriceps[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoTriceps[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoTriceps[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 2:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoCosta[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoCosta[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoCosta[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoCosta[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoCosta[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 3:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoBiceps[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoBiceps[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoBiceps[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoBiceps[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoBiceps[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 4:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoOmbro[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoOmbro[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoOmbro[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoOmbro[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoOmbro[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 5:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoAntebraco[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoAntebraco[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoAntebraco[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoAntebraco[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoAntebraco[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        case 6:
                                                            switch (i2)
                                                            {
                                                            case 0:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPerna[rot[i].segunda[i4]]);
                                                                break;
                                                            case 1:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPerna[rot[i].terca[i4]]);
                                                                break;
                                                            case 2:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPerna[rot[i].quarta[i4]]);
                                                                break;
                                                            case 3:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPerna[rot[i].quinta[i4]]);
                                                                break;
                                                            case 4:
                                                                printf("%d - %s\n", i4 + 1,
                                                                       treinoPerna[rot[i].sexta[i4]]);
                                                                break;
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    printf("\n");
                                                    rep++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            system("cls");
                            printf("-->CONSULTAR ROTINA DE TREINO<--\n\n");
                            printf("ID selecinado nao corresponde a um id existente!\n");
                            printf("Deseja tentar novamente? ");
                            char esc7[3];
                            fflush(stdin);
                            gets(esc7);
                            strlwr(esc7);
                            if (strcmp(esc7, "sim") != 0)
                            {
                                idex = 1;
                            }
                        }
                    } while (idex == 0);
                }
                else
                {
                    printf("Ainda nao existem clientes ou rotinas de treino criadas para realizar uma consulta!\n");
                }
                printf("Pressione ENTER para continuar");
                fflush(stdin);
                getchar();
            }
            else
            {
                printf("Voce negou a operacao!\n");
                printf("Pressione ENTER para continuar");
                getchar();
            }
            break;
        case 6:
            int idexiste;
            system("cls");
            printf("-->EXCLUIR CLIENTE<--\n\n");
            printf("Voce selecionou a opcao EXCLUIR CLIENTE, deseja continuar (sim ou nao)? ");
            char esc8[3];
            fflush(stdin);
            gets(esc8);
            strlwr(esc8);
            if (strcmp(esc8, "sim") == 0)
            {
                if (qtdCliente > 0)
                {
                    int excex;
                    do
                    {
                        system("cls");
                        printf("-->EXCLUIR CLIENTE<--\n\n");
                        printf("Deseja excluir um cliente pelo seu id ou pelo nome?\n1- ID\n2-Nome\nOPCAO: ");
                        scanf("%d", &excex);
                        if (excex == 1)
                        {
                            system("cls");
                            printf("-->EXCLUIR CLIENTE PELO ID<--\n\n");
                            for (int i = 0; i < qtdCliente; i++)
                            {
                                printf("ID: %04d\n", cl[i].codigo);
                            }
                            do
                            {
                                idexiste = 0;
                                printf("Digite o ID do cliente que deseja excluir: ");
                                int idExc;
                                scanf("%d", &idExc);
                                for (int i = 0; i < qtdCliente; i++)
                                {
                                    if (idExc == cl[i].codigo)
                                    {
                                        if (cl[i].rot == 1)
                                        {
                                            for (int ii2 = 0; ii2 < qtdRotina; ii2++)
                                            {
                                                if (idExc == rot[ii2].codCliente)
                                                {
                                                    for (int ii = ii2; ii < qtdRotina - 1; ii++)
                                                    {
                                                        rot[ii].codigo = rot[ii + 1].codigo;
                                                        rot[ii].codCliente = rot[ii + 1].codCliente;
                                                        for (int i2 = 0; i2 < 5; i2++)
                                                        {
                                                            rot[ii].segunda[i2] = rot[ii + 1].segunda[i2];
                                                            rot[ii].terca[i2] = rot[ii + 1].terca[i2];
                                                            rot[ii].quarta[i2] = rot[ii + 1].quarta[i2];
                                                            rot[ii].quinta[i2] = rot[ii + 1].quinta[i2];
                                                            rot[ii].sexta[i2] = rot[ii + 1].sexta[i2];
                                                        }
                                                        for (int i2 = 0; i2 < 5; i2++)
                                                        {
                                                            for (int i3 = 0; i3 < 2; i3++)
                                                            {
                                                                rot[ii].ordem[i2][i3] = rot[ii + 1].ordem[i2][i3];
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            qtdRotina--;
                                        }
                                        for (int ii = i; ii < qtdCliente - 1; ii++)
                                        {
                                            cl[ii].codigo = cl[ii + 1].codigo;
                                            strcpy(cl[ii].nome, cl[ii + 1].nome);
                                            cl[ii].idade = cl[ii + 1].idade;
                                            cl[ii].peso = cl[ii + 1].peso;
                                            cl[ii].altura = cl[ii + 1].altura;
                                            cl[ii].precoMens = cl[ii + 1].precoMens;
                                            cl[ii].sexo = cl[ii + 1].sexo;
                                            cl[ii].rot = cl[ii + 1].rot;
                                        }
                                        idexiste = 1;
                                    }
                                }
                                if (idexiste == 0)
                                {
                                    printf("ID digitado Inexistente. ");
                                }
                            } while (idexiste == 0);
                        }
                        else if (excex == 2)
                        {
                            system("cls");
                            printf("-->EXCLUIR CLIENTE PELO NOME<--\n\n");
                            for (int i = 0; i < qtdCliente; i++)
                            {
                                printf("Nome: %s\n", cl[i].nome);
                            }
                            do
                            {
                                printf("Digite o nome do Cliente que deseja excluir: ");
                                char nomeExc[100];
                                fflush(stdin);
                                gets(nomeExc);
                                for (int i = 0; i < qtdCliente; i++)
                                {
                                    if (strcmp(cl[i].nome, nomeExc) == 0)
                                    {
                                        if (cl[i].rot == 1)
                                        {
                                            for (int ii = 0; ii < qtdRotina; ii++)
                                            {
                                                if (cl[i].codigo == rot[ii].codCliente)
                                                {
                                                    for (int i2 = ii; i2 < qtdRotina - 1; i2++)
                                                    {
                                                        rot[i2].codigo = rot[i2 + 1].codigo;
                                                        rot[i2].codCliente = rot[i2 + 1].codCliente;
                                                        for (int i3 = 0; i3 < 5; i3++)
                                                        {
                                                            rot[i2].segunda[i3] = rot[i2 + 1].segunda[i3];
                                                            rot[i2].terca[i3] = rot[i2 + 1].terca[i3];
                                                            rot[i2].quarta[i3] = rot[i2 + 1].quarta[i3];
                                                            rot[i2].quinta[i3] = rot[i2 + 1].quinta[i3];
                                                            rot[i2].sexta[i3] = rot[i2 + 1].sexta[i3];
                                                        }
                                                        for (int i3 = 0; i3 < 5; i3++)
                                                        {
                                                            for (int i4 = 0; i4 < 2; i4++)
                                                            {
                                                                rot[i2].ordem[i3][i4] = rot[i2 + 1].ordem[i3][i4];
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            qtdRotina--;
                                        }
                                        for (int ii = i; ii < qtdCliente - 1; ii++)
                                        {
                                            cl[ii].codigo = cl[ii + 1].codigo;
                                            strcpy(cl[ii].nome, cl[ii + 1].nome);
                                            cl[ii].idade = cl[ii + 1].idade;
                                            cl[ii].peso = cl[ii + 1].peso;
                                            cl[ii].altura = cl[ii + 1].altura;
                                            cl[ii].precoMens = cl[ii + 1].precoMens;
                                            cl[ii].sexo = cl[ii + 1].sexo;
                                            cl[ii].rot = cl[ii + 1].rot;
                                        }
                                        idexiste = 1;
                                    }
                                }
                                if (idexiste == 0)
                                {
                                    printf("Nome digitado Inexistente. ");
                                }
                            } while (idexiste == 0);
                        }
                        else
                        {
                            system("cls");
                            printf("-->EXCLUIR CLIENTE<--\n\n");
                            printf("Opcao Invalida!\n");
                            fflush(stdin);
                            getchar();
                        }
                    } while (excex != 1 && excex != 2);
                    qtdCliente--;
                    system("cls");
                    printf("-->EXCLUIR CLIENTE<--\n\n");
                    printf("Cliente excluido com sucesso!\n");
                }
                else
                {
                    system("cls");
                    printf("-->EXCLUIR CLIENTE<--\n\n");
                    printf("Nao existem registros de cliente para serem excluidos!\n");
                }
            }
            else
            {
                printf("Voce negou essa operacao!\n");
            }
            printf("Pressione ENTER para continuar\n");
            fflush(stdin);
            getchar();
            break;
        case 7:
            system("cls");
            printf("-->EXCLUIR PRIMEIRO CLIENTE<--\n\n");
            printf("O cliente de:\nCodigo: %04d\nNome: %s\nIdade: %d\nfoi excluido!\n", cl[0].codigo, cl[0].nome, cl[0].idade);
            if (qtdCliente > 0)
            {
                for (int i = 0; i < qtdRotina - 1; i++)
                {
                    if (rot[i].codCliente == cl[0].codigo)
                    {
                        rot[i].codigo = rot[i + 1].codigo;
                        rot[i].codCliente = rot[i + 1].codCliente;
                        for (int ii = 0; ii < 5; ii++)
                        {
                            rot[i].segunda[ii] = rot[i + 1].segunda[ii];
                            rot[i].terca[ii] = rot[i + 1].terca[ii];
                            rot[i].quarta[ii] = rot[i + 1].quarta[ii];
                            rot[i].quinta[ii] = rot[i + 1].quinta[ii];
                            rot[i].sexta[ii] = rot[i + 1].sexta[ii];
                        }
                        for (int ii = 0; ii < 5; ii++)
                        {
                            for (int i2 = 0; i2 < 2; i2++)
                            {
                                rot[i].ordem[ii][i2] = rot[i + 1].ordem[ii][i2];
                            }
                        }
                    }
                }
                for (int i = 0; i < qtdCliente - 1; i++)
                {
                    cl[i].codigo = cl[i + 1].codigo;
                    strcpy(cl[i].nome, cl[i + 1].nome);
                    cl[i].idade = cl[i + 1].idade;
                    cl[i].peso = cl[i + 1].peso;
                    cl[i].altura = cl[i + 1].altura;
                    cl[i].precoMens = cl[i + 1].precoMens;
                    cl[i].sexo = cl[i + 1].sexo;
                    cl[i].rot = cl[i + 1].rot;
                }
                qtdCliente--;
                qtdRotina--;
            }
            else
            {
                printf("Nao existe nenhum registro de cliente para ser excluido!\n");
            }
            printf("Pressione ENTER para continuar.");
            fflush(stdin);
            getchar();
            break;
        case 0:
            system("cls");
            printf("-->ENCERRAR PROGRAMA<--\n\n");
            printf("Voce selecionou a opcao SAIR, tem certeza que deseja realizar essa operacao(sim ou nao)? ");
            char escS[3];
            fflush(stdin);
            gets(escS);
            strlwr(escS);
            if (strcmp(escS, "sim") == 0)
            {
                system("cls");
                printf("-->ENCERRAR PROGRAMA<--\n\n");
                printf("PROGRAMA ENCERRADO! Obrigado por Utilizar a Academia Privadinho dos BB's\n");
            }
            else
            {
                system("cls");
                printf("-->ENCERRAR PROGRAMA<--\n\n");
                printf("Retornando ao MENU, pressione ENTER para continuar.");
                fflush(stdin);
                getchar();
                op = 999;
            }
            break;
        }
    } while (op != 0);
    return 0;
}