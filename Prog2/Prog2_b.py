from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import sys

#####################################################################################
file_name = sys.argv[1]
threshold = int(sys.argv[2])
output_name = file_name.split('.')
output_name.pop(-1)
output_name = '.'.join(output_name)
output_name += '_b_out.pgm'
#####################################################################################
'''input file and check if it is valid form'''
#read file into a list
f = open(file_name, 'rb')
L = []
for line in f:
    L.append(str(line, encoding = "ascii"))
f.close()
#change each line into str data type
for i in range(len(L)):
    temp_L = list(L[i])
    #remove the \n in the end of each line
    temp_L.pop(-1)
    temp_S = ''.join(temp_L)
    L[i] = temp_S
#if can't find P2 in the file return error and quit
if 'P2' not in L[0]:
    print('Error!')
    sys.exit()
#if P2 in the first line, then pop it and continue
else:
    L.pop(0)
#####################################################################################
'''remove the first four line of data and get the size of this pgm'''
#remove all line started with #
while L[0][0] == '#':
    L.pop(0)
#check the space between two size and save it as another variable
if '  ' in L[0]:
    size = L[0].split('  ')
else:
    size = L[0].split(' ')
L.pop(0)
#get the maximum
max = L[0]
L.pop(0)
for i in range(len(L)):
    temp_L = L[i].split('  ')
    L[i] = temp_L
#####################################################################################
'''reshape the remaining data into a matrix by numpy and build a new matrix as the backup to do detection'''
new_L = []
for elem in L:
    new_L += elem
    
data = np.array(new_L)
data = data.reshape(int(size[1]),int(size[0]))
data = data.astype(int)
new_data = np.zeros((int(size[1]),int(size[0])))
#####################################################################################
'''do the Edge Detection'''
for row in range(int(size[1])):
    for column in range(int(size[0])):
        '''
        T means target
        1 2 3
        4 T 5
        6 7 8
        '''
        # the most outside pixel will be set white
        if row == 0 or column == 0 or row == int(size[1])-1 or column == int(size[0])-1:
            new_data[row][column] = 255
            continue
        # the middle pixel will be determined by the around eight pixels
        else:
            I = data[row-1][column-1]
            II = data[row-1][column]
            III = data[row-1][column+1]
            IV = data[row][column-1]
            V = data[row][column+1]
            VI = data[row+1][column-1]
            VII = data[row+1][column]
            VIII = data[row+1][column+1]
            # compute the average value of this pixel
            SUM = I + II + III + IV + V + VI + VII + VIII
            AVG = SUM/8
        # the avtivate is a variable to determine the remaining level
        activate = threshold
		
		###this part can change the activate freely###
		
        if data[row][column] - AVG > activate:
            new_data[row][column] = 0
        elif data[row][column] - AVG <= activate:
            new_data[row][column] = 255
#####################################################################################
'''output the detected image and original image'''
new_im = Image.fromarray(new_data.astype(np.uint8))
new_im.save(output_name)