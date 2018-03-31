from Tkinter import *
from tkFileDialog import *
import matplotlib.pyplot as plt
import numpy as np



#читает состояние из файла и активирует его на поле
def read_from_file():
    clear()
    i = 0
    re = askopenfilename()
    if re =="":
        return 0
    f = open(re, 'r')
    for line in f:
        cur_line = line.split()
        for j in xrange(num_cells_x):    
            if cur_line[j] == "1":
                canvas.itemconfig(cell_matrix[addr(i,j)], state = NORMAL, tag = 'vis')
            else:
                canvas.itemconfig(cell_matrix[addr(i,j)], state = HIDDEN, tags = ('hid','0'))
        i += 1
    f.close()
#осуществляет запись текущего состояния в файл
def write_to_file():
    sa = asksaveasfilename()
    if sa == "":
        return 0
    f = open(sa, 'w')
    for i in xrange(num_cells_y):
        for j in xrange(num_cells_x):
            if (canvas.gettags(cell_matrix[addr(i,j)])[0] == 'hid'):
                f.write('. ')
            else:
                f.write('1 ')
        f.write('\n')
    f.write('\n')
    f.close()
##строит диаграмму текущего состояния клеток
def diagramm():
    count = 0
    for i in xrange(num_cells_y):
        for j in xrange(num_cells_x):
            if (canvas.gettags(cell_matrix[addr(i,j)])[0] == 'hid'):
                count += 1
    count_vis = num_cells_y*num_cells_x - count
    plt.figure(figsize = (7,5))
    x = [count_vis, count]
    labels = ['Living', 'Dead']
    plt.pie(x, labels = labels, autopct = '%1.1f%%', shadow = True)
    plt.show()

##оживляет клетку по нажатию на нее
def active_life(event):
    i = (event.y)/cell_size
    j = (event.x)/cell_size
    if (canvas.gettags(cell_matrix[addr(i, j)])[0] == 'hid'):
        canvas.itemconfig(cell_matrix[addr(i,j)], state = NORMAL, tag = 'vis')
    else:
        canvas.itemconfig(cell_matrix[addr(i,j)], state = HIDDEN, tags = ('hid','0'))

##преобразует двумерную координату в одномерную
def addr(i,j):
    if(i < 0 or j < 0 or i >= num_cells_y or j >= num_cells_x):	
        return len(cell_matrix) - 1
    else:
        return i*(field_width) + j

##считает количество живых клеток вокруг и меняет тег клетки для дальнейшего преобразования
def around():
    for i in xrange(num_cells_y):
        for j in xrange(num_cells_x):
            k = 0
            for around_i in xrange(-1, 2):
                if ((around_i + i) == -1):
                    y = num_cells_y - 1
                elif ((around_i + i) == num_cells_y):
                    y = 0
                else:
                    y = around_i + i
                for around_j in xrange(-1, 2):
                    if ((around_j + j) == -1):
                        x = num_cells_x - 1
                    elif ((around_j + j) == num_cells_x):
                        x = 0
                    else: 
                        x = around_j + j
                    if (canvas.gettags(cell_matrix[addr(y, x)])[0] == 'vis' and (around_i != 0 or around_j != 0)):
                        k += 1
            current_tag = canvas.gettags(cell_matrix[addr(i,j)])[0]
            if (k == 3):
                canvas.itemconfig(cell_matrix[addr(i,j)], tags = (current_tag, 'to_vis'))
            if (k<=1 or k>=4):
                canvas.itemconfig(cell_matrix[addr(i,j)], tags = (current_tag, 'to_hid'))
            if (k==2 and canvas.gettags(cell_matrix[addr(i,j)])[0] == 'vis'):
                canvas.itemconfig(cell_matrix[addr(i,j)], tags = (current_tag, 'to_vis'))


##отрисовывает очередной шаг
def paint():
    for i in xrange (num_cells_y):
        for j in xrange (num_cells_y):
            if (canvas.gettags(cell_matrix[addr(i,j)])[1] == 'to_hid'):
                canvas.itemconfig(cell_matrix[addr(i,j)], state = HIDDEN, tags = ('hid', '0'))
            if (canvas.gettags(cell_matrix[addr(i,j)])[1] == 'to_vis'):
                canvas.itemconfig(cell_matrix[addr(i,j)], state = NORMAL, tags = ('vis', '0'))

##выполняет один шаг игры
def one_step():
    around()
    paint()

##очищает поле
def clear():
    for i in xrange(num_cells_y):
        for j in xrange(num_cells_x):
            canvas.itemconfig(cell_matrix[addr(i,j)], state = HIDDEN, tags = ('hid', '0'))


num_cells_x = int(input('Введите количество клеток в ширину\n'))
num_cells_y = int(input('Введите количество клеток в высоту\n'))
cell_size = 10
win_width = num_cells_x*cell_size
win_height = num_cells_y*cell_size
root = Tk()
root_config = "{0}x{1}".format(win_width, win_height + 32)
root.geometry(root_config)
root.title('The Game of Life')
canvas = Canvas(root, width = win_width, height = win_height, bg = "black")
canvas.pack()
cell_matrix = []
field_height = win_height/cell_size
field_width = win_width/cell_size
for i in xrange(num_cells_y):
    for j in xrange(num_cells_x):
        square = canvas.create_rectangle(2 + cell_size*j, 2 + cell_size*i, cell_size + cell_size*j - 2, cell_size + cell_size*i - 2 , fill="green")
        canvas.itemconfig(square, state=HIDDEN, tags=('hid', '0'))
        cell_matrix.append(square)
menu1 = Menu(root)
root.config(menu = menu1)
fm = Menu(menu1)
menu1.add_cascade(label = 'Analysis', menu = fm)
fm.add_command(label = 'Write to file', command = write_to_file)
fm.add_command(label = 'Create Diagram', command = diagramm)
fm.add_command(label = 'Read state', command = read_from_file)
frame = Frame(root)
btn_clear = Button(frame, text = 'Clear', command = clear)
btn_step = Button(frame, text = 'Step', command = one_step)
btn_step.pack(side = 'left')
btn_clear.pack(side = 'right')
frame.pack(side = 'bottom')
canvas.bind('<Button-1>', active_life)
root.mainloop()
