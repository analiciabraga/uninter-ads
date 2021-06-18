#def parangaricu():
 #   palavra1 = 'parangaricu'
  #  tirimirruaro(palavra1)

#def tirimirruaro(palavra):
 #   palavra2 = palavra + 'tirimirruaro'
    #print(palavra2)

#parangaricu()
#print(palavra2)

#parangaricutirimirruaro

#for i in range(89, 1, -4):
 #  print(i)

#i = 89
#while (i >= 0):
  #  print(i)
  #  i -= 4

##def valida_peso(kg, min):  # função de validação para peso ser número positivo
#   peso = float(input(kg))
 #  while (kg < min):
  #    peso = float(input(kg))
   #return peso

### EXERCÍCIO 1 - LUTADORES E CATEGORIAS ###
#####___RU 3423922 ### ANA BRAGA_______#####

#ex4  CAIXA ELETRÔNICO
print(' CAIXA ELETRÔNICO')
print('+'+('-'*16)+'+')

#valor = int(input('Digite o valor que deseja sacar:'))

while True:
    valor = int(input('Digite o valor que deseja sacar:'))
    if valor >= 100:
        cedulas100 = valor // 100
        valor -= cedulas100 * 100
        print('Cédulas de 100: {}'.format(cedulas100))
        if not valor:
            break
    if valor >= 50:
        cedulas50 = valor // 50
        valor -= cedulas50 * 50
        print('Cédulas de 50: {}'.format(cedulas50))
        if not valor:
            break
    if valor >= 20:
        cedulas20 = valor // 20
        valor -= cedulas20 * 20
        print('Cédulas de 20: {}'.format(cedulas20))
        if not valor:
            break
    if valor >= 10:
        cedulas10 = valor // 10
        valor -= cedulas10 * 10
        print('Cédulas de 10: {}'.format(cedulas10))
        if not valor:
            break
    if valor >= 5:
        cedulas5 = valor // 5
        valor -= cedulas5 * 5
        print('Cédulas de 5: {}'.format(cedulas5))
        if not valor:
            break
    if valor:
        cedulas1 = valor
        print('Cédulas de 1: {}'.format(cedulas1))
        break