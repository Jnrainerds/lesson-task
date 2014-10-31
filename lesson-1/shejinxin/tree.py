#!/bin/python2
#encoding:utf-8
import os

ignore_files = ['.git']

def lstree(path,depth = 0):
    """ Display tree,ignore depth which is use for recursion
    """
    files = os.listdir(path)
    for item in files:
        if item in ignore_files:
            # Ignore file in ignore_files
            continue
        _print_item(item,depth)
        itempath = path + '/'+ item
        if os.path.isdir(itempath):
            lstree(itempath,depth+1)

def _print_item(item,depth):
    print "%s└── %s" % (depth*"    ",item)

if __name__ == '__main__':
    lstree('.')
