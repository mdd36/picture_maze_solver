from PIL import Image
from sys import argv

fname = argv[1] if len(argv > 1) else ""
fPath = './../data/{}.png'.format(fname)
im = Image.open(fPath)
pix = im.load()
width, height = im.size

raw = list()
for y in range(height):
    row = list()
    for x in range(width):
        row.append(str(pix[x, y]))
    row.append('\n')
    raw.append(''.join(row))

out = ''.join(raw)

with open('./../input/{}.txt'.format(fname), "w+") as file:
    file.write(out)