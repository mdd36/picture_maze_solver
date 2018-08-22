from PIL import Image
from sys import argv

colors = [(0, 0, 0), (255, 255, 255), (255, 0, 0)]
fname = argv[1] if len(argv) > 1 else "medDijkstra"
fPath = './../output/txt/{}.txt'.format(fname)

with open(fPath, 'r') as file:
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
        pix[x, y] = parsed[y][x]

im.save('./../output/im/{}.png'.format(fname), 'PNG')
