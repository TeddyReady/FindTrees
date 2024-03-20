import matplotlib.pyplot as plt

if __name__ == "__main__":


    range_x = [1000000,100000,10000,5000,2000,1000,500,100]
    plot1 = [13138,235,11,4,1,0,0,0]
    # plot2 = [1000000,60042,381,73,11,2,0,0]
    plot3 = [266,19,2,1,0,0,0,0]
    plot4 = [1171,45,2,1,0,0,0,0]
    errors = [998533,98537,8620,3822,1208,479,204,33]

    plt.plot(range_x, plot1, linewidth=1.0)
    # plt.plot(range_x, plot2, linewidth=1.0)
    plt.plot(range_x, plot3, linewidth=1.0)
    plt.plot(range_x, plot4, linewidth=1.0)
    plt.legend(('Бинарное дерево', 'КЧ дерево', 'Хеш-таблица', 'Стандартный словарь'))
    plt.show()

    plt.plot(range_x, errors, linewidth=1.0)
    plt.legend(("Число коллизий",))
    plt.show()
