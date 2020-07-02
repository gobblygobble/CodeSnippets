import os

# open all files in current directory
for filename in os.listdir(os.getcwd()):
    with open(os.path.join(os.getcwd(), filename), 'r') as f:
        # work with files that end with '.txt'
        if not filename.endswith(".txt"):
            continue
        # note that f.name will return filename!
        print("NEW FILE: {}".format(filename))
        for line in f:
            print(line.rstrip())

