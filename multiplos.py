limite = 4000000
sequencia = [0,1]
def fibonacci(n):
    while len(sequencia) <n:
        proximo_termo = sequencia[-1] + sequencia[-2]
        sequencia.append(proximo_termo)
                         
    return sequencia

n = 4000000

sequencia = fibonacci(n)
soma = sum(sequencia)

print("a sequencia dos", n , "termos é:", sequencia)
print("a soma dos termos é:", soma)
