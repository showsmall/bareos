from time import time as now

fn = open('time.out', 'w+')
fn.write('%s' % now())
fn.close()
