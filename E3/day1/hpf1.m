clear; 
close all;
clc;

s = tf('s');
R = 1000;
C = 0.1 * 10^(-6);
G = (C*R*s)/(C*R*s+1);

figure; step(G); grid on;
saveas(gcf, 'hpf1_step.png');
figure; bode(G); grid on;
saveas(gcf, 'hpf1_bode.png');

figure; pzmap(G);
xlim([-wn,wn]);ylim([-wn,wn]);
daspect([1 1 1]);
saveas(gcf, 'hpf1_bode_pzmap');