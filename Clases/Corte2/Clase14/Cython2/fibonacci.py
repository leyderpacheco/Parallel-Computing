def fibonacci(n):
    a=0.0
    b=1.0
    for i in range(n):
        b=a
        a,b = a, a+b
    return a