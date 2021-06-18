### EXERCÍCIO 1 - LUTADORES E CATEGORIAS ###
#####___RU 3423922 ### ANA BRAGA_______#####

while True:
    print('+'+('-'*8)+'QUAL É A CATEGORIA DO LUTADOR?'+('-'*8)+'+') ##cabeçalho
    NomeLut = input('Digite o nome do Lutador ou Sair para finalizar o programa: ') #Variável tipo string para receber o dado nome

    if NomeLut.upper() == 'SAIR': #Condição para encerramento do loop com tratamento de case sensitive
        break
    else:
        PesoLut = float(input('Digite o peso do lutador: '))  # Variável para receber o dado peso após validação
        Cat = 'Nenhuma'  # Declaração da variável que vai registrar a categoria
        if (PesoLut < 65): #Se o peso for menor que 65, categoria recebe string Pena
            Cat = 'Pena'
        elif (65 <= PesoLut < 72): #Se o peso estiver entre 65 e 71, categoria recebe string Leve
            Cat = 'Leve'
        elif (72 <= PesoLut < 79): #Se o peso estiver entre 72 e 78, categoria recebe string Ligeiro
            Cat = 'Ligeiro'
        elif (79 <= PesoLut < 86): #Se o peso estiver entre 72 e 86, categoria recebe string Meio-médio
            Cat = 'Meio-médio'
        elif (86 <= PesoLut < 93): #Se o peso estiver entre 72 e 93, categoria recebe string Médio
            Cat = 'Médio'
        elif (93 <= PesoLut < 100): #Se o peso estiver entre 93 e 100, categoria recebe string Meio-pesado
            Cat = 'Meio-pesado'
        else:
            Cat = 'Pesado' #Se não contemplar nenhuma das opções acima, categoria recebe string Pesado

        print('Nome fornecido: {}'.format(NomeLut))
        print('Peso fornecido: {}'.format(PesoLut))
        print('O lutador {} pesa {} Kg e se enquadra na categoria {}.'.format(NomeLut, PesoLut, Cat))


### EXERCÍCIO 2 - CÓDIGO E DÍGITO VERIFICADOR ###
#####___RU 3423922 ######## ANA BRAGA_______#####

def inicia_encerra(encerrar):
    while True:
        if encerrar.upper() not in 'NS':
            print('Digite S ou N')
        if encerrar.upper() in 'N':  # comando para encerrar o programa
            break
        if encerrar.upper() in 'S':  # comando para forçar o tipo de opção S ou N (continuar ou encerrar o programa
            return


def valida_cod(cod, min, max): #função para validar o código do produto
    x = input(cod)
    while not x.isdigit() or (x := int(x)) < min or x > max: #verifica se o número é inteiro e está no intervalo informado
        print('Código inválido') #caso o número não seja válido ou não seja número
        inicia_encerra(input('Deseja consultar um código? [S/N]'))
    return str(x) #retorna o valor em formato string para proceder com o fatiamento na função cria_dv

def cria_dv(num): #função para cálculo do dígito verificador
    dv = 0
    n = 0
    alg = 2
    for item in num:
        n += (alg * int(item))
        alg += 1
    dv = (n % 7)
    return (dv)

###### PROGRAMA PRINCIPAL #####

print('+'+('-'*8)+'CALCULE O DÍGITO VERIFICADOR'+('-'*8)+'+') ##cabeçalho

if inicia_encerra(input('Deseja consultar um código? [S/N]')):
    codigo = valida_cod('Digite o código do produto: ', 10000, 30000)
    dig = cria_dv(codigo)
    print('O código do produto é {}-{}'.format(int(codigo), dig))

##### EXERCÍCIO 3 - ALUNOS APROVADOS E MÉDIA ####
#####___RU 3423922 ######## ANA BRAGA_______#####

from pandas import DataFrame #importação de função do pandas para formatação da tabela de saída

cadastro = {'Nome': [], 'N1': [], 'N2': [], 'N3': [], 'N4': [], 'Sit': []} #dicionário com listas
media = 0
quant = 0

while True:
    terminar = input('Deseja cadastrar alunos? [S/N]') #comando para iniciar ou encerrar o programa
    if terminar.upper() in 'N':  # pode usar o upper ou colocar n minúsculo na pesquisa
        break
    if terminar.upper() not in 'S':
        print('Digite S ou N')
        continue
    quant = int(input('Qual o número de alunos?')) #entrada de número de alunos
    for i in range(quant): #loop para povoar o dicionário com os dados solicitados
        nome = input('Digite o nome do aluno {}: '.format(i+1))
        nota1 = float(input('Digite a nota 1: ')) #recebe dados do tipo float
        nota2 = float(input('Digite a nota 2: '))
        nota3 = float(input('Digite a nota 3: '))
        nota4 = float(input('Digite a nota 4: '))
        media = ((nota1 + nota2 + nota3 + nota4)//4) #cálculo da média

        cadastro['Nome'].append(nome) #inclusão dos dados nas listas do dicionário cadastro
        cadastro['N1'].append(nota1)
        cadastro['N2'].append(nota2)
        cadastro['N3'].append(nota3)
        cadastro['N4'].append(nota4)
        if media < 7: #condição para ser aprovado ou reprovado
            cadastro['Sit'].append('Reprovado')
        else:
            cadastro['Sit'].append('Aprovado')
    print('- ' * 10) #formatação para saída
    print('  Notas dos alunos')
    print('- '*10)
    print(DataFrame(data=cadastro)) #impressão da tabela com os dados dos alunos
    print('- ' * 20) #separador para próximo cadastro

##### EXERCÍCIO 4 - AGENDA DE CONTATOS ####
#####___RU 3423922 ######## ANA BRAGA_#####

agenda = {} #dicionário parte 1 do exercício
agendaMaior = {} #dicionários parte 2 (maiores)
agendaMenor = {} #dicionário parte 2 (menores)
idade = 0 #declaração de variáveis
telefone = 0

while True:
    comando = input('Digite o nome do contato ou tecle enter para finalizar: ') #comando para encerrar o programa
    if comando == '':  # se a entrada é uma string vazia, o programa é encerrado, apresentando os resultados
        break
    nome = comando
    idade = int(input('Digite a idade: ')) #recebe idade do tipo inteiro
    telefone = int(input('Digite o telefone: ')) #recebe telefone tipo inteiro
    agenda[nome] = {'Idade': idade, 'Telefone': telefone} #inclusão dos dados nas listas do dicionário cadastro

    for item in sorted(agenda.items()): #impressão do dicionário ordenado pela chave nome
        print(item[0], ':', item[1])

    for r in agenda.values(): #divisão do dicionário inicial em 2 novos dicionários
        if idade <= 17: #se menor, inserido no dicionário de menores
            agendaMenor[nome] = {'Idade': idade, 'Telefone': telefone}
        elif idade > 17: #se maior, inserido no dicionário de maiores
            agendaMaior[nome] = {'Idade': idade, 'Telefone': telefone}

agenda.clear() # elimina o dicionário original
print('- ' * 10) #formatação para saída
print('  Agenda de Maiores')
print('- '*10)
for item in sorted(agendaMaior.items()): #imprime o dicionário de maiores, ordenado pelo nome
    print(item[0], ':', item[1])
print('- ' * 20) #separador para próxima agenda

print('- ' * 10)  # formatação para saída
print('  Agenda de Menores')
print('- ' * 10)
for item in sorted(agendaMenor.items()): #imprime o dicionário de menores, ordenado pelo nome
    print(item[0], ':', item[1])  # impressão da tabela com os dados dos alunos