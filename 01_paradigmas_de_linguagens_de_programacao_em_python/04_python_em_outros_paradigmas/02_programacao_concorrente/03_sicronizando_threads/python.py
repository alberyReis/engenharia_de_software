import threading
import time

# Sincronizando threads

ls = []

def contador01(n):
  for i in range(1, n + 1):
    print(i)
    ls.append(i)
    time.sleep(0.4)

def contador02(n):
  for i in range(6, n + 1):
    print(i)
    ls.append(i)
    time.sleep(0.5)

x = threading.Thread(target = contador01, args = (5,))
x.start()

x.join()

y = threading.Thread(target = contador02, args = (10,))
y.start()

y.join()

print(ls)