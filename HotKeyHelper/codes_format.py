with open("codes_raw.txt", mode="r") as f, open("codes_formatted.txt", mode="w") as g:
    size = 0
    while True:
        try:
            code, pretty = f.readline().strip().split('\t')
            g.write('{L"' + code + '", L"' + pretty.ljust(26) + ' (' + code + ')"},\n')
            size += 1
        except:
            break
    print(size)