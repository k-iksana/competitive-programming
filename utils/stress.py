import random
import os
import sys

NUMBER_OF_TESTS = 1000
path = "input"

solution = "D.exe"
test = "slow-D.exe"

def get_random_int(left, right):
    return random.randint(left, right)

def get_random_array(size, left, right):
    return [get_random_int(left, right) for i in range(size)]

def str_int(x):
    return f"{x}\n";

def str_array(arr):
    line = ""
    for i in range(len(arr) - 1):
        line += f"{arr[i]} "
    line += f"{arr[len(arr) - 1]}\n"
    return line
 
def gen_input():
    test = "1\n";
    n = get_random_int(1, 10)
    a = get_random_array(n, 1, n)
    b = get_random_array(n, 1, n)
    test += str_int(n)
    test += str_array(a)
    test += str_array(b)
    return test

def stress():
    if not os.path.exists("input"):
        os.mkdir("input")
    if not os.path.exists("output"):
        os.mkdir("output")
    # for _ in range(NUMBER_OF_TESTS):
    while (True):
        with open("input/test.in", 'w') as f:
            f.write(gen_input())
        f.close()
        os.system(f"{solution} < input/test.in > output/solution.out")
        os.system(f"{test} < input/test.in > output/test.out")  
        f1 = open('output/solution.out', 'r')
        f2 = open('output/test.out', 'r')
        x = f1.read()   
        lx = x.split()
        y = f2.read()
        ly = y.split()
        if (y != x):
            f3 = open('input/test.in', 'r')
            z = f3.read()
            print(z)
            print(x)
            print(y)
            break;

print(gen_input())
stress()
