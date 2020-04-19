import webbrowser as web
import argparse

def main():
    path = ""

    rows, cols = args()
    tour = get_info("knight's tour.txt")
    html = get_info("tamplateA.html")

    for i in range(0, len(tour) - 2, 3):
        path += str((int(tour[i])*4) + (int(tour[i+1])*2) + (int(tour[i+2])))
        if (i%2 == 0):
            path += ","
        else:
            path += " "

    html = html.replace("[rows]", "{}".format(rows))
    html = html.replace("[cols]", "{}".format(cols))
    html = html.replace("{}", path[:-1])

    with open("path.html", 'w') as f:
        f.write(html)
    f.close()

    # open the web browser site of the path created
    web.register('firefox', None, web.BackgroundBrowser("C://Program Files//Mozilla Firefox//firefox.exe"))
    web.get('firefox').open("path.html")
    

def args():
    parser = argparse.ArgumentParser(description='help visualize the chess board moves', prog='Knight')
    parser.add_argument('N', metavar='N', type=int, help='an integer of the amount of rows')
    parser.add_argument('M', metavar='M', type=int, help='an integer of the amount of cols')
    args = parser.parse_args()
    return (args.N + 1), (args.M + 1)

def get_info(file_name):
    with open("{}".format(file_name), 'r') as f:
        read = f.read()
    f.close()
    return read


if __name__ == '__main__':
    main()
