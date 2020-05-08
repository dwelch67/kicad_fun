
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static FILE *fp;

#define IOSMIDGE 1.74
#define WEEBIT   1.00

int main ( void )
{
    double degrad;

    double vccgnd;

    //double angle;
    //double rangle;
    //double tangle;
    //double gangle;
    //double vangle;
    //double zangle;
    //double x,y;
    double ax,ay;
    double bx,by;
    //double cx,cy;
    //double xangle[360];
    //double xax[360];
    //double xay[360];



    //double xgndx[360];
    //double xgndy[360];
    //double xvccx[360];
    //double xvccy[360];


    //double xinx[360];
    //double xiny[360];
    //double xoutx[360];
    //double xouty[360];

    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rd;
    unsigned int net;

    degrad = 1.0 / 180.0 * M_PI;
    vccgnd = sqrt((2.7*2.7)+(1.65*1.65));

    //gangle = atan(YPAD/RGVIA);
    //gangle = (gangle * 180.0) / M_PI;
    //vangle = atan(YPAD/RVVIA);
    //vangle = (vangle * 180.0) / M_PI;
////printf("gangle %lf\n",gangle);
////printf("vangle %lf\n",vangle);

    //zangle = atan(YPAD/RING_BASE);
    //zangle = (zangle * 180.0) / M_PI;

    //zangle = ((360.0/DIVISIONS) - zangle)*2.0;
////printf("zangle %lf\n",zangle);


    //angle = 0.0;
    //for(ra=0;ra<DIVISIONS;ra++,angle+=(360.0/DIVISIONS))
    //{
        //rangle=angle*degrad;
        //x = cos(rangle);
        //y = -sin(rangle);
        //xangle[ra]=angle;
        //xax[ra]=x;
        //xay[ra]=y;

        //tangle=rangle+atan(YPAD/(RING_BASE-XPAD));

        //x = cos(tangle);
        //y = -sin(tangle);
        //xgndx[ra]=x;
        //xgndy[ra]=y;

        //tangle=rangle-atan(YPAD/(RING_BASE+XPAD));

        //x = cos(tangle);
        //y = -sin(tangle);
        //xvccx[ra]=x;
        //xvccy[ra]=y;


        //tangle=rangle+atan(YPAD/(RING_BASE+XPAD));

        //x = cos(tangle);
        //y = -sin(tangle);
        //xoutx[ra]=x;
        //xouty[ra]=y;


        //tangle=rangle-atan(YPAD/(RING_BASE-XPAD));

        //x = cos(tangle);
        //y = -sin(tangle);
        //xinx[ra]=x;
        //xiny[ra]=y;




    //}


    fp=fopen("npixclock.kicad_pcb","wt");
    if(fp==NULL) return(1);

    fprintf(fp,"(kicad_pcb (version 4) (host pcbnew 4.0.7-e2-6376~58~ubuntu16.04.1)\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (general\n");
    fprintf(fp,"    (links 0)\n");
    fprintf(fp,"    (no_connects 0)\n");
    fprintf(fp,"    (area 150 100 180 100)\n");
    fprintf(fp,"    (thickness 1.6)\n");
    fprintf(fp,"    (drawings 2)\n");
    fprintf(fp,"    (tracks 0)\n");
    fprintf(fp,"    (zones 0)\n");
    fprintf(fp,"    (modules 0)\n");
    fprintf(fp,"    (nets 28)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (page A4)\n");
    fprintf(fp,"  (layers\n");
    fprintf(fp,"    (0 F.Cu signal)\n");
    fprintf(fp,"    (31 B.Cu signal)\n");
    fprintf(fp,"    (32 B.Adhes user)\n");
    fprintf(fp,"    (33 F.Adhes user)\n");
    fprintf(fp,"    (34 B.Paste user)\n");
    fprintf(fp,"    (35 F.Paste user)\n");
    fprintf(fp,"    (36 B.SilkS user)\n");
    fprintf(fp,"    (37 F.SilkS user)\n");
    fprintf(fp,"    (38 B.Mask user)\n");
    fprintf(fp,"    (39 F.Mask user)\n");
    fprintf(fp,"    (40 Dwgs.User user)\n");
    fprintf(fp,"    (41 Cmts.User user)\n");
    fprintf(fp,"    (42 Eco1.User user)\n");
    fprintf(fp,"    (43 Eco2.User user)\n");
    fprintf(fp,"    (44 Edge.Cuts user)\n");
    fprintf(fp,"    (45 Margin user)\n");
    fprintf(fp,"    (46 B.CrtYd user)\n");
    fprintf(fp,"    (47 F.CrtYd user)\n");
    fprintf(fp,"    (48 B.Fab user)\n");
    fprintf(fp,"    (49 F.Fab user)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (setup\n");
    fprintf(fp,"    (last_trace_width 0.25)\n");
    fprintf(fp,"    (trace_clearance 0.2)\n");
    fprintf(fp,"    (zone_clearance 0.508)\n");
    fprintf(fp,"    (zone_45_only no)\n");
    fprintf(fp,"    (trace_min 0.2)\n");
    fprintf(fp,"    (segment_width 0.2)\n");
    fprintf(fp,"    (edge_width 0.15)\n");
    fprintf(fp,"    (via_size 0.6)\n");
    fprintf(fp,"    (via_drill 0.4)\n");
    fprintf(fp,"    (via_min_size 0.4)\n");
    fprintf(fp,"    (via_min_drill 0.3)\n");
    fprintf(fp,"    (uvia_size 0.3)\n");
    fprintf(fp,"    (uvia_drill 0.1)\n");
    fprintf(fp,"    (uvias_allowed no)\n");
    fprintf(fp,"    (uvia_min_size 0.2)\n");
    fprintf(fp,"    (uvia_min_drill 0.1)\n");
    fprintf(fp,"    (pcb_text_width 0.3)\n");
    fprintf(fp,"    (pcb_text_size 1.5 1.5)\n");
    fprintf(fp,"    (mod_edge_width 0.15)\n");
    fprintf(fp,"    (mod_text_size 1 1)\n");
    fprintf(fp,"    (mod_text_width 0.15)\n");
    fprintf(fp,"    (pad_size 1.524 1.524)\n");
    fprintf(fp,"    (pad_drill 0.762)\n");
    fprintf(fp,"    (pad_to_mask_clearance 0.2)\n");
    fprintf(fp,"    (aux_axis_origin 0 0)\n");
    fprintf(fp,"    (visible_elements FFFFFF7F)\n");
    fprintf(fp,"    (pcbplotparams\n");
    fprintf(fp,"      (layerselection 0x00030_80000001)\n");
    fprintf(fp,"      (usegerberextensions false)\n");
    fprintf(fp,"      (excludeedgelayer true)\n");
    fprintf(fp,"      (linewidth 0.150000)\n");
    fprintf(fp,"      (plotframeref false)\n");
    fprintf(fp,"      (viasonmask false)\n");
    fprintf(fp,"      (mode 1)\n");
    fprintf(fp,"      (useauxorigin false)\n");
    fprintf(fp,"      (hpglpennumber 1)\n");
    fprintf(fp,"      (hpglpenspeed 20)\n");
    fprintf(fp,"      (hpglpendiameter 15)\n");
    fprintf(fp,"      (hpglpenoverlay 2)\n");
    fprintf(fp,"      (psnegative false)\n");
    fprintf(fp,"      (psa4output false)\n");
    fprintf(fp,"      (plotreference true)\n");
    fprintf(fp,"      (plotvalue true)\n");
    fprintf(fp,"      (plotinvisibletext false)\n");
    fprintf(fp,"      (padsonsilk false)\n");
    fprintf(fp,"      (subtractmaskfromsilk false)\n");
    fprintf(fp,"      (outputformat 1)\n");
    fprintf(fp,"      (mirror false)\n");
    fprintf(fp,"      (drillshape 1)\n");
    fprintf(fp,"      (scaleselection 1)\n");
    fprintf(fp,"      (outputdirectory \"\"))\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (net 0 \"\")\n");
    fprintf(fp,"  (net 1 gnd)\n");
    fprintf(fp,"  (net 2 vcc)\n");
    fprintf(fp,"  (net 3 io00)\n");
    fprintf(fp,"  (net 4 io01)\n");
    fprintf(fp,"  (net 5 io02)\n");
    fprintf(fp,"  (net 6 io03)\n");
    fprintf(fp,"  (net 7 io04)\n");
    fprintf(fp,"  (net 8 io05)\n");
    fprintf(fp,"  (net 9 io06)\n");
    fprintf(fp,"  (net 10 io07)\n");
    fprintf(fp,"  (net 11 io08)\n");
    fprintf(fp,"  (net 12 io09)\n");
    fprintf(fp,"  (net 13 io10)\n");
    fprintf(fp,"  (net 14 io11)\n");
    fprintf(fp,"  (net 15 io12)\n");
    fprintf(fp,"  (net 16 io13)\n");
    fprintf(fp,"  (net 17 io14)\n");
    fprintf(fp,"  (net 18 io15)\n");
    fprintf(fp,"  (net 19 io16)\n");
    fprintf(fp,"  (net 20 io17)\n");
    fprintf(fp,"  (net 21 io18)\n");
    fprintf(fp,"  (net 22 io19)\n");
    fprintf(fp,"  (net 23 io20)\n");
    fprintf(fp,"  (net 24 io21)\n");
    fprintf(fp,"  (net 25 io22)\n");
    fprintf(fp,"  (net 26 io23)\n");
    fprintf(fp,"  (net 27 io24)\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (net_class Default \"This is the default net class.\"\n");
    fprintf(fp,"    (clearance 0.2)\n");
    fprintf(fp,"    (trace_width 0.25)\n");
    fprintf(fp,"    (via_dia 0.6)\n");
    fprintf(fp,"    (via_drill 0.4)\n");
    fprintf(fp,"    (uvia_dia 0.3)\n");
    fprintf(fp,"    (uvia_drill 0.1)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");

//fprintf(fp,"  (gr_text NPIXRING%u (at 145 100 270) (layer F.SilkS)\n",DIVISIONS/2);
//fprintf(fp,"    (effects (font (size 1.5 1.5) (thickness 0.3)))\n");
//fprintf(fp,"  )\n");


by=0.0;
net=0;
for(rb=0;rb<3;rb++)
{
    ax=150.0; ay=100.0+by;
    for(ra=0;ra<4;ra++)
    {
        fprintf(fp,"(module 00_my_modules:WS2812b (layer F.Cu) (tedit 5EB4DDC7) (tstamp 5EB4E6F6)\n");
        fprintf(fp,"  (at %10.5lf %10.5lf 45)\n",ax,ay);
        fprintf(fp,"  (fp_line (start -2.5 -2.5) (end 2.5 -2.5) (layer F.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start -2.5 2.5) (end 2.5 2.5) (layer F.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start -2.5 -2.5) (end -2.5 2.5) (layer F.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start 2.5 -2.5) (end 2.5 2.5) (layer F.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start 1.5 2.5) (end 2.5 1.5) (layer F.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start 2.65 0.5) (end 2.65 -0.5) (layer F.SilkS) (width 0.1))\n");
        fprintf(fp,"  (pad VCC smd rect (at -2.7 -1.65 45) (size 2 1) (layers F.Cu F.Paste F.Mask)  (net 2 vcc))\n");
        fprintf(fp,"  (pad OUT smd rect (at -2.7 1.65 45) (size 2 1) (layers F.Cu F.Paste F.Mask)(net %u io%02u))\n",net+4,net+1);
        fprintf(fp,"  (pad GND smd rect (at 2.7 1.65 45) (size 2 1) (layers F.Cu F.Paste F.Mask)  (net 1 gnd))\n");
        fprintf(fp,"  (pad IN smd rect (at 2.7 -1.65 45) (size 2 1) (layers F.Cu F.Paste F.Mask)(net %u io%02u))\n",net+3,net); net++;
        fprintf(fp,")\n");

        fprintf(fp,"(module 00_my_modules:C_0603 (layer B.Cu) (tedit 5415CC62) (tstamp 5EB4EA02)\n");
        fprintf(fp,"  (at %10.5lf %10.5lf)\n",ax,ay);
        fprintf(fp,"  (fp_line (start -1.2 0.45) (end 1.2 0.45) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start -1.2 -0.45) (end 1.2 -0.45) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start -1.2 0.45) (end -1.2 -0.45) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (fp_line (start 1.2 0.45) (end 1.2 -0.45) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"  (pad VCC smd rect (at -0.75 0) (size 0.8 0.8) (layers B.Cu B.Paste B.Mask)(net 2 vcc))\n");
        fprintf(fp,"  (pad GND smd rect (at 0.75 0) (size 0.8 0.8) (layers B.Cu B.Paste B.Mask)(net 1 gnd))\n");
        fprintf(fp,")\n");


        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer B.Cu) (net 1))\n",ax+0.75,ay,ax+1.68,ay);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 1))\n",ax+1.68,ay);

        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer B.Cu) (net 2))\n",ax-0.75,ay,ax-1.68,ay);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 2))\n",ax-1.68,ay);

        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 2))\n",ax-1.68,ay,ax-3.075914,ay+0.742462);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 1))\n",ax+1.68,ay,ax+3.075914,ay-0.742462);


if(ra==0)
{

    if(rb==0)
    {
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 2))\n",ax-3.075914,ay+0.742462,145.0,ay+0.742462);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 1))\n",ax+3.075914,ay-0.742462,145.0,ay-0.742462);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net %u))\n",ax+0.742462,ay-3.075914,145.0,ay-3.075914,net);
    }

    if((rb==1)||(rb==2))
    {

        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net %u))\n"   ,ax+0.742462+IOSMIDGE       ,ay-4    ,ax+0.742462    ,ay-3.075914,net);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu)(net %u))\n"                 ,ax+0.742462+IOSMIDGE       ,ay-4    ,net);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net %u))\n"   ,ax-0.742462-IOSMIDGE+24    ,ay-4    ,ax-0.742462+24 ,ay+3.075914-8,net);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu)(net %u))\n"                 ,ax-0.742462-IOSMIDGE+24    ,ay-4    ,net);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer B.Cu) (net %u))\n"   ,ax+0.742462+IOSMIDGE       ,ay-4    ,ax-0.742462-IOSMIDGE+24    ,ay-4,net);
    }




    if(rb<2)
    {
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 2))\n",ax-3.075914,ay+0.742462,ax-3.075914,ay+0.742462+8);
    }
}
if(ra==3)
{
    if(rb<2)
    {
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 1))\n",ax+3.075914,ay-0.742462,ax+3.075914,ay-0.742462+8);
    }
}

if(ra<3)
{
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 2))\n",ax-3.075914,ay+0.742462,ax-3.075914+8,ay+0.742462);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net 1))\n",ax+3.075914,ay-0.742462,ax+3.075914+8,ay-0.742462);

        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu) (net %u))\n"   ,ax-0.742462            ,ay+3.075914    ,ax-0.742462+  IOSMIDGE,ay+3.075914,net);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu)(net %u))\n"                 ,ax-0.742462+  IOSMIDGE ,ay+3.075914    ,net);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer F.Cu)(net %u))\n"    ,ax+0.742462+8          ,ay-3.075914    ,ax+0.742462+8-IOSMIDGE,ay-3.075914,net);
        fprintf(fp,"(via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu)(net %u))\n"                 ,ax+0.742462+8-IOSMIDGE ,ay-3.075914    ,net);
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.25) (layer B.Cu)(net %u))\n"    ,ax-0.742462+  IOSMIDGE ,ay+3.075914    ,ax+0.742462+8-IOSMIDGE,ay-3.075914,net);
}

        ax+=8.0;
    }
    by+=8.0;
}






    fprintf(fp,"\n");
    fprintf(fp,")\n");
    fclose(fp);
    return(0);
}
