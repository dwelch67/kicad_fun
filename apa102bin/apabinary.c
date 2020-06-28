
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static FILE *fp;


#define ROWS 3
#define COLS 4
#define SPACING 8.0
#define STARTBACK 8.0

#define GNDNET  1
#define FIVENET 2
#define VCCNET  3
#define DINNET  4
#define CINNET  5



int main ( void )
{
    unsigned int ra;
    unsigned int rx,ry;
    double ax,ay;
    double bx,by;
    double cx,cy;
    double dx,dy;
    double degrad;
    double angle;
    //double rangle;

    unsigned int dodi[ROWS][COLS];
    unsigned int coci[ROWS][COLS];


    degrad = M_PI / 180.0;

    angle=0.0;
    //rangle=angle*degrad;
    //x = cos(rangle);
    //y = -sin(rangle);
    //xangle[ra]=angle;
    //xax[ra]=x;
    //xay[ra]=y;


    fp=fopen("apabinary.kicad_pcb","wt");
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
    fprintf(fp,"    (nets 1)\n");
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
    fprintf(fp,"    (last_trace_width 0.20)\n");
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
    fprintf(fp,"  (net 2 five)\n");
    fprintf(fp,"  (net 3 vcc)\n");
    fprintf(fp,"  (net 4 din)\n");
    fprintf(fp,"  (net 5 cin)\n");
    ra=6;
    for(ry=0;ry<ROWS;ry++)
    {
        for(rx=0;rx<COLS;rx++)
        {
            fprintf(fp,"  (net %u dodi%u%u)\n",ra,ry,rx);
            dodi[ry][rx]=ra;
            ra++;
        }
    }
    for(ry=0;ry<ROWS;ry++)
    {
        for(rx=0;rx<COLS;rx++)
        {
            fprintf(fp,"  (net %u coci%u%u)\n",ra,ry,rx);
            coci[ry][rx]=ra;
            ra++;
        }
    }
    fprintf(fp,"\n");
    fprintf(fp,"  (net_class Default \"This is the default net class.\"\n");
    fprintf(fp,"    (clearance 0.2)\n");
    fprintf(fp,"    (trace_width 0.20)\n");
    fprintf(fp,"    (via_dia 0.6)\n");
    fprintf(fp,"    (via_drill 0.4)\n");
    fprintf(fp,"    (uvia_dia 0.3)\n");
    fprintf(fp,"    (uvia_drill 0.1)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");

//fprintf(fp,"  (gr_text APABIN (at 145 100 270) (layer B.SilkS)\n");
//fprintf(fp,"    (effects (font (size 1.5 1.5) (thickness 0.3))(justify mirror) )\n");
//fprintf(fp,"  )\n");

    dy=100.0;
    for(ry=0;ry<ROWS;ry++,dy+=SPACING)
    {
        dx=100.0;
        for(rx=0;rx<COLS;rx++,dx+=SPACING)
        {
//printf("%u %u %lf %lf \n",rx,ry,dy,dx);
            fprintf(fp,"(module 00_my_modules:X (layer F.Cu) (tedit 5415CC62) (tstamp 5EA86CD9)\n");
            fprintf(fp,"    (at  %10.5lf %10.5lf %10.5lf)\n",dx,dy,angle);
            //fprintf(fp,"(fp_circle (center 2.413 3.048) (end 2.4765 3.1115) (layer F.SilkS) (width 0.15))\n");
            fprintf(fp,"(fp_circle (center 0 0) (end 0 2.0) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start  2.5   2.5) (end -2.5   2.5) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start  2.5  -2.5) (end -2.5  -2.5) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start  2.5   2.5) (end  2.5  -2.5) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start -2.5   2.5) (end -2.5  -2.5) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start -1.5  -2.5) (end -2.5  -1.5) (layer F.CrtYd) (width 0.01))\n");
            fprintf(fp,"(fp_line (start -2.5 2.5) (end -2.7 2.5) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start  2.5 2.5) (end  2.7 2.5) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start -2.5 -2.5) (end -2.7 -2.5) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start  2.5 -2.5) (end  2.7 -2.5) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start -2.5  2.5) (end -2.5  2.7) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start  2.5  2.5) (end  2.5  2.7) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start -2.5 -2.5) (end -2.5 -2.7) (layer F.SilkS) (width 0.1))\n");
            fprintf(fp,"(fp_line (start  2.5 -2.5) (end  2.5 -2.7) (layer F.SilkS) (width 0.1))\n");

            fprintf(fp,"(fp_line (start -2.7 -2.5) (end -2.5 -2.7) (layer F.SilkS) (width 0.1))\n");



if(rx==0)
{
    if(ry==0)
    {
            fprintf(fp,"(pad XX  smd rect (at  -2.6 -1.7 %10.5lf) (size 2.2 1.1) (layers B.Mask))\n",angle);
            fprintf(fp,"(pad DI  smd rect (at  -2.6 -1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u din))\n",angle,DINNET);
    }
    else
    {
            fprintf(fp,"(pad DI  smd rect (at  -2.6 -1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u dodi%u%u))\n",angle,dodi[ry-1][COLS-1],ry-1,COLS-1);
    }
}
else
{
            fprintf(fp,"(pad DI  smd rect (at  -2.6 -1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u dodi%u%u))\n",angle,dodi[ry][rx-1],ry,rx-1);
}


if(rx==0)
{
    if(ry==0)
    {
            fprintf(fp,"(pad CI  smd rect (at  -2.6 -0.0 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u cin))\n",angle,CINNET);
    }
    else
    {
            fprintf(fp,"(pad CI  smd rect (at  -2.6 -0.0 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u coci%u%u))\n",angle,coci[ry-1][COLS-1],ry-1,COLS-1);
    }
}
else
{
            fprintf(fp,"(pad CI  smd rect (at  -2.6 -0.0 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u coci%u%u))\n",angle,coci[ry][rx-1],ry,rx-1);
}
            fprintf(fp,"(pad GND smd rect (at  -2.6  1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u gnd))\n",angle,GNDNET);
            fprintf(fp,"(pad 5V  smd rect (at   2.6  1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u five))\n",angle,FIVENET);
            fprintf(fp,"(pad CO  smd rect (at   2.6 -0.0 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u coci%u%u))\n",angle,coci[ry][rx],ry,rx);
            fprintf(fp,"(pad DO  smd rect (at   2.6 -1.7 %10.5lf) (size 2.2 1.1) (layers F.Cu F.Paste F.Mask)(net %u dodi%u%u))\n",angle,dodi[ry][rx],ry,rx);



//if(rx<(COLS-1))
//{
            ////DO
            //fprintf(fp,"(fp_line (start 2.6 -1.7) (end 5.0 -1.7) (layer F.Cu) (width 0.2))\n");
            ////CO
            //fprintf(fp,"(fp_line (start 2.6 -0.0) (end 5.0 -0.0) (layer F.Cu) (width 0.2))\n");
//}
            ////VCC
            //fprintf(fp,"(fp_line (start  2.6  1.7) (end  2.6 3.4) (layer F.Cu) (width 0.20))\n");
            ////GND
            //fprintf(fp,"(fp_line (start -2.6  1.7) (end 0 1.7) (layer F.Cu) (width 0.20))\n");

            fprintf(fp,"  )\n");

if(rx<(COLS-1))
{
            //DO
            //fprintf(fp,"(fp_line (start 2.6 -1.7) (end 5.0 -1.7) (layer F.Cu) (width 0.2))\n");
            ax=dx+2.6;
            ay=dy-1.7;
            bx=dx+5.0;
            by=dy-1.7;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

            //CO
            //fprintf(fp,"(fp_line (start 2.6 -0.0) (end 5.0 -0.0) (layer F.Cu) (width 0.2))\n");
            ax=dx+2.6;
            ay=dy-0.0;
            bx=dx+5.0;
            by=dy-0.0;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
}
            //VCC
            //fprintf(fp,"(fp_line (start  2.6  1.7) (end  2.6 3.4) (layer F.Cu) (width 0.20))\n");
            ax=dx+2.6;
            ay=dy+1.7;
            bx=dx+2.6;
            by=dy+3.4;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
            //GND(pad GND smd rect (at  -2.6  1.7
            //fprintf(fp,"(fp_line (start -2.6  1.7) (end 0 1.7) (layer F.Cu) (width 0.20))\n");
            ax=dx-2.6;
            ay=dy+1.7;
            bx=dx+0.0;
            by=dy+1.7;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
            //gnd
            ////(end 0 1.7)
            ax=dx+0.0;
            ay=dy+1.7;
            fprintf(fp,"(via (at %10.5lf %10.5lf ) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",ax,ay);
        }



        if(ry==0)
        {
            //DI  (at  -2.6 -1.7
            ax=100.0-2.6;
            ay=100.0-1.7;
            bx=100.0-STARTBACK;
            by=ay;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

            //CI  (at  -2.6 -0.0
            ax=100.0-2.6;
            ay=100.0-0.0;
            bx=100.0-STARTBACK;
            by=ay;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        }

        //GND
        //(end 0 1.7)

        ax=dx+0.0-SPACING;
        ay=dy+1.7;
        bx=ax-SPACING;
        by=ay;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
        ax=bx-SPACING;
        ay=by;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
        bx=ax-SPACING;
        by=ay;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
        ax=100.0-5.0;
        ay=by;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
        if(ry==0)
        {
            fprintf(fp,"(via (at %10.5lf %10.5lf ) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",ax,ay);
            bx=ax;
            by=ay;
            cx=100-0-STARTBACK;
            cy=by;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",cx,cy,bx,by);

            bx=ax;
            by=by+SPACING;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
            ax=ax;
            ay=by+SPACING;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer B.Cu) (net 0))\n",ax,ay,bx,by);
        }

        //VCC
        //(end  2.6 3.4)
        ax=dx+2.6-SPACING;
        ay=dy+3.4;
        bx=ax-SPACING;
        by=ay;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        ax=bx-SPACING;
        ay=by;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        bx=ax-SPACING;
        by=ay;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        ax=100.0-5.0;
        ay=by;
        fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        if(ry==0)
        {
            bx=ax;
            by=ay;
            cx=100-0-STARTBACK;
            cy=by;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",cx,cy,bx,by);

            bx=ax;
            by=by+SPACING;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
            ax=ax;
            ay=by+SPACING;
            fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        }

if(rx<(COLS-1))
{
}
else
{
    if(ry<(ROWS-1))
    {

    //(at   2.6 -1.7 %10.5lf)
    ax=dx+2.6-SPACING;
    ay=dy-1.7;
    bx=ax+2.5;
    by=ay;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    ax=bx;
    ay=by+1.7+3.4+0.6+0.6;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    bx=100.0-2.6;
    by=ay;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    ax=bx;
    ay=dy+SPACING-1.7;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

    //(at   2.6 -0.0 %10.5lf)
    ax=dx+2.6-SPACING;
    ay=dy-0.0;
    bx=ax+1.8;
    by=ay;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    ax=bx;
    ay=by+3.4+0.6;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    bx=100.0-2.6-1.8; //(at  -2.6 -1.7
    by=ay;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    ax=bx;
    ay=dy+SPACING;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
    bx=ax+1.8;
    by=ay;
    fprintf(fp,"(segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.20) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

    }
}

    }


    //ax=150.0-(RING_BASE+7);
    //bx=150.0+(RING_BASE+7);
    //ay=100.0-(RING_BASE+7);
    //by=100.0+(RING_BASE+7);
    //fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",ax,ay,ax,by);
    //fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",bx,ay,bx,by);
    //fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,ay,bx,ay);
    //fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,by,bx,by);

    fprintf(fp,"\n");
    fprintf(fp,")\n");
    fclose(fp);
    return(0);
}
