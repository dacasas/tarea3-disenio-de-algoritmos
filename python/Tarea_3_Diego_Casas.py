from test_primalidad import test_primalidad
from integer import Integer


def get_tuples(file_dir):
    f = open(file_dir, "r")
    read = f.read().split(", ")
    f.close()
    tests = []
    for i in range(0, len(read), 2):
        elem = read[i].rstrip()
        if (i + 1 < len(read)):
            k = read[i + 1].rstrip()
            tests.append((Integer(elem), int(k)))
        else:
            print("The file does not match (odd quantity of numbers)")
            exit(0)
    return tests


def write_results(results, file_dir):
    f = open(file_dir, "w")
    for i in range(0, len(results)):
        if (i == len(results) - 1):
            f.write(results[i])
        else:
            f.write(results[i] + ", ")

    f.close()


def show_welcome():
    print("Welcome to primality test, to begin, select one option...")
    print("[1] Read from a file, write in 'output.txt'.")
    print("[2] Read from console, shows the result in console.")
    print("[3] Exit program.")
    user_input = input("Write an index and press enter: ")
    user_input = int(user_input.rstrip())
    return user_input


exit = False
while (not exit):
    user_input = show_welcome()

    if (user_input == 1):
        user_input = input("Enter the filename you want to test:\n")
        file_dir = user_input.rstrip()

        if (file_dir != ""):
            tests = get_tuples(file_dir)
            results = []
            print("Calculating...")
            for tupla in tests:
                res = test_primalidad(tupla[0], tupla[1])
                results.append(res)
            write_results(results, "output.txt")
            print("Done.\n")

        else:
            print("You must enter a file name")

    elif (user_input == 2):
        user_input = input("Enter the number you want to know if is prime: ")
        n_raw = user_input.rstrip()

        user_input = input("Enter the quantity of random numbers you want: ")
        k_raw = user_input.rstrip()

        if (n_raw != "" and k_raw != ""):
            print("Calculating...")
            n = Integer(n_raw)
            k = int(k_raw)
            print(test_primalidad(n, k) + "\n")
        else:
            print("You must enter both numbers")

    elif (user_input == 3):
        print("Exiting...")
        exit = True

    else:
        print("You must select a valid option")
