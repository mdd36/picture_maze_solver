from PIL import Image
from sys import argv

colors = [(0,0,0), (255,255,255), (255,0,0)]
with open('./../output/txt/simple_dfs.txt', 'r') as file:
# with open('./../output/' + argv[1] + '.txt', 'r') as file:
    raw = file.readlines()

parsed = list()
for line in raw:
    line = line[:-1]
    row = line.split(",")
    temp = [colors[int(pixel)] for pixel in row]
    parsed.append(temp)

width = len(parsed[0])
height = len(parsed)

im = Image.new('RGB', (width, height))
pix = im.load()
for y in range(height):
    for x in range(width):
        pix[x,y] = parsed[y][x]

im.save('img1.png', 'PNG')
