close all; clear; clc; s = tf('s');
C = 4.7 * 10^(-10);
L = 47*10^(-6); % [microH]
wn = 1/sqrt(L*C); % calc wn
zeta = [0,0.2,1/sqrt(2),1];

R = 2*zeta*sqrt(L/C) % calc theoretical R to select feasible R

%C = 1/(4*pi^2*(10^12)*L);

R1 = 0; zeta1 = R1/2*sqrt(C/L); fprintf('zeta1=%f\n',zeta1);
R2 = 1.5*10^2; zeta2 = R2/2*sqrt(C/L); fprintf('zeta2=%f\n',zeta2);
R3 = 4.7*10^2; zeta3 = R3/2*sqrt(C/L); fprintf('zeta3=%f\n',zeta3);
R4 = 6.8*10^2; zeta4 = R4/2*sqrt(C/L); fprintf('zeta4=%f\n',zeta4);

% transfer functions
G1 = (wn^2)/(s^2+2*zeta1*wn*s+wn^2);
G2 = (wn^2)/(s^2+2*zeta2*wn*s+wn^2);
G3 = (wn^2)/(s^2+2*zeta3*wn*s+wn^2);
G4 = (wn^2)/(s^2+2*zeta4*wn*s+wn^2);

figure; bode(G1,G2,G3,G4);
grid on;    % show grid
legend;     % show legend
saveas(gcf, 'rlc_bode2.png');   % save as png file

figure; pzmap(G1,G2,G3,G4);
daspect([1 1 1]);               % aspect ratio
legend('Location','northwest'); % show legend
saveas(gcf, 'rlc_pzmap2.png');  % save as png file

figure; step(G1,G2,G3,G4);  % step response
grid on;    % show grid
legend;     % show legend
xlim([0,1e-5]);
saveas(gcf, 'rlc_step2.png');   % save as png file
