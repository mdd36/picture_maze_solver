from PIL import Image
from sys import argv

colors = {'0': (0, 0, 0), '1': (255, 255, 255), '2': (255, 0, 0), '3': (0, 255, 0), '4': (0, 255, 255)}

with open('./../data/modified.txt', 'r') as file:
#with open('./../out/' + argv[1] + '.txt', 'r') as file:
    raw = file.readlines()

parsed = list()
for line in raw:
    line = line[:-1]
    temp = list()
    for pixel in line:
        temp.append(colors[pixel])
    parsed.append(temp)

width = len(parsed[0])
height = len(parsed)

im = Image.new('RGB', (width, height))
pix = im.load()
for y in range(height):
    for x in range(width):
        pix[x,y] = parsed[y][x]

im.save('img1.png', 'PNG')
