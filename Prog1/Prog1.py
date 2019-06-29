import copy
import random

#read the file and remove the space
file = open('input.txt','r')
S = file.read()
L = S.split(' ')
S = ''.join(L)
file.close
#the original list of x1 x2 x3 ....  xn
Ori_L = [0,1,2,3,4,5,6,7,8,9]
#######################################################################
#Optimal (Clear)
OP_L = copy.deepcopy(Ori_L)
times = [0,0,0,0,0,0,0,0,0,0]
OP_result = []
for word in S:
    times[int(word)] += 1
for i in range(0,10):
    M = max(times)
    OP_L[i] = times.index(M)
    times[times.index(M)] = -1
#calculate the different term
for terms in range(50,1001,50):
    total_count = 0
    for word in range(0,terms):
        counter = 0
        while True:
            if int(S[word]) == OP_L[counter]:
                counter += 1
                total_count += counter
                break
            else:
                counter += 1
                continue
    OP_result.append(total_count)
print('Optimal: ',OP_result)
#######################################################################
#MTF (Clear)
def move_to_front(L,index):
    '''move the element to the front(index = 0)'''
    if index == 0:
        return None
    temp = L.pop(index)
    L.insert(0,temp)
MTF_result = []
    
for terms in range(50,1001,50):
    MTF_L = copy.deepcopy(Ori_L)
    total_count = 0
    for word in range(0,terms):
        counter = 0
        while True:
            if int(S[word]) == MTF_L[counter]:
                move_to_front(MTF_L,counter)
                counter += 1
                total_count += counter
                break
            else:
                counter += 1
                continue
    MTF_result.append(total_count)
print('MTF: ',MTF_result)
#######################################################################
#bit (Clear)
def init_bit(L):
    '''initialize the list of bit to each number'''
    for i in range(0,10):
        L[i] = random.randint(0,1)
    return L
BIT_L = copy.deepcopy(Ori_L)
bit = [0,0,0,0,0,0,0,0,0,0]
bit = init_bit(bit)
INIT_bit = bit
BIT_result = [] 

for terms in range(50,1001,50):
    BIT_L = copy.deepcopy(Ori_L)
    bit = INIT_bit
    total_count = 0
    for word in range(0,terms):
        counter = 0
        while True:
            if int(S[word]) == BIT_L[counter]:
                if bit[counter] == 1:
                    bit[counter] = 0
                    counter += 1
                    total_count += counter
                    break
                else:
                    bit[counter] = 1
                    move_to_front(BIT_L,counter)
                    move_to_front(bit,counter)
                    counter += 1
                    total_count += counter
                    break
            else:
                counter += 1
                continue
    BIT_result.append(total_count)
print('BIT: ',BIT_result)
print(INIT_bit)
#######################################################################
#transpose (Clear)
def transpose(L,index):
    '''function to change elements in L[index] and L[index - 1] '''
    if index == 0:
        return None
    temp = L[index - 1]
    L[index - 1] = L[index]
    L[index] = temp
T_result = []

for terms in range(50,1001,50):
    T_L = copy.deepcopy(Ori_L)
    total_count = 0
    for word in range(0,terms):
        counter = 0
        while True:
            if int(S[word]) == T_L[counter]:
                transpose(T_L,counter)
                counter += 1
                total_count += counter
                break
            else:
                counter += 1
                continue
    T_result.append(total_count)
print('Transpose: ',T_result)
#######################################################################
#frequency count (Clear)
def rearrange(number_L,frequency,index):
    '''according to the frequency to rearrange the List'''
    if index == 0:
        return None
    for i in range(index-1,-1,-1):
        if frequency[i] < frequency[i + 1]:
            temp = frequency[i]
            frequency[i] = frequency[i + 1]
            frequency[i + 1] = temp
            temp = number_L[i]
            number_L[i] = number_L[i + 1]
            number_L[i + 1] = temp
FC_result = []

for terms in range(50,1001,50):
    MAX = 0
    FC_L = copy.deepcopy(Ori_L)
    access_frequency = [0,0,0,0,0,0,0,0,0,0]
    total_count = 0
    for word in range(0,terms):
        counter = 0
        while True:
            if int(S[word]) == FC_L[counter]:
                access_frequency[counter] += 1
                rearrange(FC_L,access_frequency,counter)
                counter += 1
                total_count += counter
                break
            else:
                counter += 1
                continue
    FC_result.append(total_count)
print('frequency count: ',FC_result)
#######################################################################
#write result into file
file = open('output.txt','w')

file.write('Optimal:\n')
for elem in OP_result:
    file.write(str(elem))
    file.write('\n')
file.write('MTF:\n')
for elem in MTF_result:
    file.write(str(elem))
    file.write('\n')
file.write('Transpose:\n')
for elem in T_result:
    file.write(str(elem))
    file.write('\n')
file.write('BIT:\n')
for elem in INIT_bit:
    file.write(str(elem))
file.write('\n')
for elem in BIT_result:
    file.write(str(elem))
    file.write('\n')
file.write('FC:\n')
for elem in FC_result:
    file.write(str(elem))
    file.write('\n')
file.close()