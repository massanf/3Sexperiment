clear; 
close all;
clc;

s = tf('s');
R = 1000; 
C = 0.1 * 10^(-6);
G = 1/(R*C*s+1);

figure; step(G); grid on;
saveas(gcf,'lpf1_step.png');
figure; bode(G); grid on;
saveas(gcf,'lpf1_bode.png');
figure;pzmap(G);
saveas(gcf,'lpf1_pzmap.png');