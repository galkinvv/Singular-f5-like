LIB "tst.lib";LIB "dmod.lib";
tst_init();
ring R = 0,(x(1..7)),dp;
poly F = -x(1)^2*x(2)*x(4)-x(1)*x(2)^2*x(4)-x(1)^2*x(3)*x(4)-3*x(1)*x(2)*x(3)*x(4)-x(2)^2*x(3)*x(4)-x(1)*x(3)^2*x(4)-x(2)*x(3)^2*x(4)-x(1)*x(2)*x(4)^2-x(1)*x(3)*x(4)^2-x(2)*x(3)*x(4)^2-x(1)^2*x(2)*x(5)-x(1)*x(2)^2*x(5)-x(1)^2*x(3)*x(5)-3*x(1)*x(2)*x(3)*x(5)-x(2)^2*x(3)*x(5)-x(1)*x(3)^2*x(5)-x(2)*x(3)^2*x(5)-3*x(1)*x(2)*x(4)*x(5)-x(2)^2*x(4)*x(5)-3*x(1)*x(3)*x(4)*x(5)-4*x(2)*x(3)*x(4)*x(5)-x(3)^2*x(4)*x(5)-x(2)*x(4)^2*x(5)-x(3)*x(4)^2*x(5)-x(1)*x(2)*x(5)^2-x(1)*x(3)*x(5)^2-x(2)*x(3)*x(5)^2-x(2)*x(4)*x(5)^2-x(3)*x(4)*x(5)^2-x(1)^2*x(2)*x(6)-x(1)*x(2)^2*x(6)-x(1)^2*x(3)*x(6)-3*x(1)*x(2)*x(3)*x(6)-x(2)^2*x(3)*x(6)-x(1)*x(3)^2*x(6)-x(2)*x(3)^2*x(6)-x(1)^2*x(4)*x(6)-3*x(1)*x(2)*x(4)*x(6)-x(2)^2*x(4)*x(6)-2*x(1)*x(3)*x(4)*x(6)-2*x(2)*x(3)*x(4)*x(6)-x(1)*x(4)^2*x(6)-x(2)*x(4)^2*x(6)-x(1)^2*x(5)*x(6)-2*x(1)*x(2)*x(5)*x(6)-3*x(1)*x(3)*x(5)*x(6)-2*x(2)*x(3)*x(5)*x(6)-x(3)^2*x(5)*x(6)-3*x(1)*x(4)*x(5)*x(6)-2*x(2)*x(4)*x(5)*x(6)-2*x(3)*x(4)*x(5)*x(6)-x(4)^2*x(5)*x(6)-x(1)*x(5)^2*x(6)-x(3)*x(5)^2*x(6)-x(4)*x(5)^2*x(6)-x(1)*x(2)*x(6)^2-x(1)*x(3)*x(6)^2-x(2)*x(3)*x(6)^2-x(1)*x(4)*x(6)^2-x(2)*x(4)*x(6)^2-x(1)*x(5)*x(6)^2-x(3)*x(5)*x(6)^2-x(4)*x(5)*x(6)^2-x(1)^2*x(2)*x(7)-x(1)*x(2)^2*x(7)-x(1)^2*x(3)*x(7)-3*x(1)*x(2)*x(3)*x(7)-x(2)^2*x(3)*x(7)-x(1)*x(3)^2*x(7)-x(2)*x(3)^2*x(7)-2*x(1)*x(2)*x(4)*x(7)-x(2)^2*x(4)*x(7)-2*x(1)*x(3)*x(4)*x(7)-3*x(2)*x(3)*x(4)*x(7)-x(3)^2*x(4)*x(7)-x(2)*x(4)^2*x(7)-x(3)*x(4)^2*x(7)-x(1)*x(2)*x(5)*x(7)-x(1)*x(3)*x(5)*x(7)-x(2)*x(3)*x(5)*x(7)-x(2)*x(4)*x(5)*x(7)-x(3)*x(4)*x(5)*x(7)-x(1)^2*x(6)*x(7)-3*x(1)*x(2)*x(6)*x(7)-4*x(1)*x(3)*x(6)*x(7)-3*x(2)*x(3)*x(6)*x(7)-x(3)^2*x(6)*x(7)-2*x(1)*x(4)*x(6)*x(7)-3*x(2)*x(4)*x(6)*x(7)-2*x(3)*x(4)*x(6)*x(7)-x(4)^2*x(6)*x(7)-x(1)*x(5)*x(6)*x(7)-x(3)*x(5)*x(6)*x(7)-x(4)*x(5)*x(6)*x(7)-x(1)*x(6)^2*x(7)-x(3)*x(6)^2*x(7)-x(4)*x(6)^2*x(7)-x(1)*x(2)*x(7)^2-x(1)*x(3)*x(7)^2-x(2)*x(3)*x(7)^2-x(2)*x(4)*x(7)^2-x(3)*x(4)*x(7)^2-x(1)*x(6)*x(7)^2-x(3)*x(6)*x(7)^2-x(4)*x(6)*x(7)^2+x(1)*x(2)*x(4)+x(1)*x(3)*x(4)+x(2)*x(3)*x(4)+x(1)*x(2)*x(5)+x(1)*x(3)*x(5)+x(2)*x(3)*x(5)+x(2)*x(4)*x(5)+x(3)*x(4)*x(5)+x(1)*x(2)*x(6)+x(1)*x(3)*x(6)+x(2)*x(3)*x(6)+x(1)*x(4)*x(6)+x(2)*x(4)*x(6)+x(1)*x(5)*x(6)+x(3)*x(5)*x(6)+x(4)*x(5)*x(6)+x(1)*x(2)*x(7)+x(1)*x(3)*x(7)+x(2)*x(3)*x(7)+x(2)*x(4)*x(7)+x(3)*x(4)*x(7)+x(1)*x(6)*x(7)+x(3)*x(6)*x(7)+x(4)*x(6)*x(7);
bfct(F);
tst_status(1);$