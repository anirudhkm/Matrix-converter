function [sf]=new12(u)
    ts=0.0001; vdc= 400 ;
    peak_phase_max=vdc/sqrt(3);
    x=u(2); 
    %y=u(3);
    y=mod(u(3),ts); 
    z=u(1);
    mag=(z/peak_phase_max)*ts;

    %Sector I
    if (x>=0) && (x<pi/3)
        n=1;
        ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
        t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
        v1=[0 1 1 1 1 1 0];v2=[0 0 1 1 1 0 0];v3=[0 0 0 1 0 0 0];
        
        for j=1:7
     if(y<t1(j))
        break
     end
        end
    sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
    end
    %Sector II
    if (x>=pi/3) && (x<2*pi/3)
        %n=2;
        adv=x-pi/3;
        tb = mag * sin(pi/3-adv);ta= mag * sin(adv);
        %ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
        t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
        v1=[0 0 1 1 1 0 0];v2=[0 1 1 1 1 1 0];v3=[0 0 0 1 0 0 0];
        
        
        for j=1:7
     if(y<t1(j))
        break
     end
        end
    sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
    end
    %Sector III
    if(x>=2*pi/3) && (x<pi)
        %n=3;
        %ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
        adv=x-2*pi/3;
        ta =mag * sin(pi/3-adv);tb =mag * sin(adv);
        t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
        v1=[0 0 0 1 0 0 0];v2=[0 1 1 1 1 1 0];v3=[0 0 1 1 1 0 0];
        
        
       for j=1:7
     if(y<t1(j))
        break
     end
        end
    sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
    end
    %Sector IV
    if(x>=-pi) && (x<-2*pi/3)
        %n=4;
        %ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
        adv=x+pi;
        tb =mag * sin(pi/3-adv);ta =mag * sin(adv);
        t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
        v1=[0 0 0 1 0 0 0];v2=[0 0 1 1 1 0 0];v3=[0 1 1 1 1 1 0];
        
        
        for j=1:7
     if(y<t1(j))
        break
     end
        end
        sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
    end
    %sector V
        if(x>=-2*pi/3)&&(x<-pi/3)
         %n=5;
         %ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
        adv=x+2*pi/3;
        ta=mag*sin(pi/3-adv);tb=mag*sin(adv);
    t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
         v1=[0 0 1 1 1 0 0];v2=[0 0 0 1 0 0 0];v3=[0 1 1 1 1 1 0];
         
        for j=1:7
     if(y<t1(j))
        break
     end
        end
    sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
        end
    %sector VI
        if (x>=-pi/3) && (x<0)
            %n=6;
            %ta = mag * sin((n*pi/3)-x);tb = mag * sin(x-((n-1)*pi/3));
            adv = x+pi/3;
            tb = mag * sin(pi/3-adv);ta = mag * sin(adv);
            t0 =(ts-ta-tb);
        t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
       v1=[0 1 1 1 1 1 0];v2=[0 0 0 1 0 0 0];v3=[0 0 1 1 1 0 0];
       
        for j=1:7
     if(y<t1(j))
        break
     end
        end
   sa=v1(j);sb=~sa;sc=v2(j);sd=~sc;se=v3(j);sg=~se;
        end
       sf=[sa sb sc sd se sg];