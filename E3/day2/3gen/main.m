clear;close all; clc;
s = tf('s');
d = 1;
k = 10;
Kt = 10;
G = Kt/(s^2+d*s+k);

w = 10;
Kpid = designpid(d,k,Kt,w)
Gcl = feedback(G*Kpid, 1);
zpk(Gcl)