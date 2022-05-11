/* See LICENSE file for copyright and license details. */

#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 1;        /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 12;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 12;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 30;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= False;               /* False means bottom tab bar */

static const char *fonts[]        = { "Iosevka Nerd Font:style:medium:size=15",
                                      "JoyPixels:size=13:antialias=true:autohint=true", 
                                      "Material Design Icons-Regular:size=15"};
static const char dmenufont[]     = "Iosevka Nerd Font:style:medium:size=15";
static const char col_gray1[]     = "#222222";
static const char col_gray2[]     = "#444444";
static const char col_gray3[]     = "#bbbbbb";
static const char col_gray4[]     = "#eeeeee";
static const char col_cyan[]      = "#005577";
static const char col_red[]       = "#c80000";
static const char *colors[][3]    = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_red  },
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
/* static const char *tags[] = { "", "🌏", "🎨", "🕹", "🐧", "💻", "📰", "📂", "🔍" }; */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
/* xprop(1):
 * WM_CLASS(STRING) = instance, class
 * WM_NAME(STRING) = title
*/
  	/* class                instance    title       tags mask     iscentered   isfloating   isterminal  noswallow    monitor */
   	{ "Gimp-2.10",	        NULL,			  NULL,		    1 << 2,	      1,           0,			      0,           0,         -1 },
   	{ "Firefox",            NULL,			  NULL,		    1 << 1,			  1,           0,			      0,          -1,         -1 },
    { "St",				          NULL,       NULL,       0,            1,           0,           1,           0,         -1 },
   	{ "Brave-browser",      NULL,			  NULL,		    1 << 1,			  1,           0,			      0,           1,         -1 },
   	{ "Inkscape",	          NULL,			  NULL,		    1 << 2,	      1,           0,			      0,          -1,         -1 },
    { "Yad",				        NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "Wine",               NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "Arandr",             NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "ksnip",              NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "Pavucontrol",        NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "vokoscreen",         NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "SimpleScreenRecorder",NULL,      NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "xdman-Main",         NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "zoom",               NULL,       NULL,       0,            1,           0,           0,           0,         -1 },
  	{ "arandr",             NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "audacious",          NULL,       NULL,       0,            1,           0,           0,           0,         -1 },
  	{ "Dragon",             NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
  	{ "firefox",            NULL,       NULL,       1 << 1,       1,           0,           0,           0,         -1 },
  	{ NULL,                NULL,  "Event Tester",   0,            0,           0,           0,           1,         -1 }, /* xev */
    /* floatthings */
    { "float-st",           NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-lfub",    NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-calcurse",  NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-calc",      NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-ncmpcpp",   NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-nmtui",     NULL,       NULL,       0,            0,           1,           0,           0,         -1 },
    { "float-st-bpytop",    NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-gotop",     NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
    { "float-st-obs",       NULL,       NULL,       0,            1,           1,           0,           0,         -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
/*        symbol        arrange function */
/*0 */    { "[]=",      tile },    /* first entry is default */
/*1 */    { "[M]",      monocle },
/*2 */    { "[@]",      spiral },
/*3 */    { "[\\]",     dwindle },
/*4 */    { "H[]",      deck },
/*5 */    { "TTT",      bstack },
/*6 */    { "===",      bstackhoriz },
/*7 */    { "HHH",      grid },
/*8 */    { "###",      nrowgrid },
/*9 */    { "---",      horizgrid },
/*10*/    { ":::",      gaplessgrid },
/*11*/    { "|M|",      centeredmaster },
/*12*/    { ">M>",      centeredfloatingmaster },
/*13*/    { "><>",      NULL },    /* no layout function means floating behavior */
	        { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *rofi[]  = { "rofi", "-modi", "drun", "-show", "drun", "show-icons", "true", "-columns", "2", "-width", "45", NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#include "movestack.c"
#include "nextprevtag.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
  /*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^agstr^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
	{ MODKEY,			XK_F2,		spawn,		SHCMD("displayselect") },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("dmenuhandler") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  /* volume and brightness */
  { 0,  XF86XK_AudioMute,           spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86XK_AudioRaiseVolume,    spawn, SHCMD("pamixer -i 5; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86XK_AudioLowerVolume,    spawn, SHCMD("pamixer -d 5; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86MonBrightnessUp,        spawn, SHCMD("light -A 5; pkill -RTMIN+2 dwmblocks") },
  { 0,  XF86MonBrightnessDown,      spawn, SHCMD("light -U 5; pkill -RTMIN+2 dwmblocks") },
	{ MODKEY,			          XK_equal,	spawn, SHCMD("pamixer -i 5; pkill -RTMIN+1 dwmblocks") },
	{ MODKEY,			          XK_minus,	spawn, SHCMD("pamixer -d 5; pkill -RTMIN+1 dwmblocks") },
  { MODKEY,		            XK_0,   	spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -RTMIN+1 dwmblocks") },
  /* mpd control */
 	{ MODKEY,			          XK_p,		        	spawn,		SHCMD("mpc -p 6601 toggle") },
	{ MODKEY,			          XK_comma,	        spawn,		SHCMD("mpc -p 6601 prev") },
	{ MODKEY|ShiftMask,		  XK_comma,	        spawn,		SHCMD("mpc -p 6601 seek 0%") },
	{ MODKEY,			          XK_period,	      spawn,		SHCMD("mpc -p 6601 next") },
	{ MODKEY|ShiftMask,		  XK_period,	      spawn,		SHCMD("mpc -p 6601 repeat") },
	{ MODKEY|ALTKEY,		    XK_period,	      spawn,		SHCMD("mpc -p 6601 random") },
  { MODKEY,			          XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -5") },
	{ MODKEY|ShiftMask,		  XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -30") },
	{ MODKEY,			          XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +5") },
	{ MODKEY|ShiftMask,		  XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +30") },
  /* launch script (dmenu, etc) */
 	{ MODKEY,		            XK_BackSpace,	    spawn,	  SHCMD("sysact") },
  { MODKEY,								XK_Escape,        spawn,		SHCMD("sysact") },
  { MODKEY,           		XK_g,             spawn,		SHCMD("editconfig") },
	{ ControlMask|ALTKEY,		XK_l,   	        spawn,	  SHCMD("lock") },
  { MODKEY|ALTKEY,        XK_x,             spawn,		SHCMD("betterlockscreen --lock") },
  { MODKEY|ShiftMask,  		XK_e,             spawn,		SHCMD("pcmanfm") },
  { MODKEY|ShiftMask,  		XK_d,             spawn,		SHCMD("samedir") },
	{ MODKEY,			          XK_grave,	        spawn,	  SHCMD("dmenuunicode") },
	{ MODKEY,			          XK_a,   	        spawn,	  SHCMD("dunstctl history-pop") },
	{ MODKEY|ShiftMask,		  XK_a,   	        spawn,	  SHCMD("dunstctl close-all") },
	{ MODKEY|ControlMask,		XK_a,   	        spawn,	  SHCMD("dunstctl close") },
	{ MODKEY|ControlMask,		XK_m,   	        spawn,	  SHCMD("dmenumount") },
	{ MODKEY|ControlMask|ShiftMask,	  XK_m,   spawn,	  SHCMD("dmenuumount") },
  /* floatthings */
  { MODKEY|ShiftMask,    XK_Return,      spawn,    SHCMD("st -c float-st -g 100x25+350+200") },
  { MODKEY,              XK_e,           spawn,    SHCMD("st -c float-st-lfub -g 100x25+350+200 lfub") },
  { MODKEY|ShiftMask,    XK_c,           spawn,    SHCMD("st -c float-st-calcurse -g 100x25+350+200 calcurse") },
  { MODKEY,              XK_apostrophe,  spawn,    SHCMD("st -c float-st-calc -g 50x20+660+275 bc -lq") },
  { MODKEY|ShiftMask,    XK_m,           spawn,    SHCMD("st -c float-st-ncmpcpp -g 100x25+350+200 ncmpcpp") },
  { MODKEY|ControlMask,  XK_n,           spawn,    SHCMD("st -c float-st-nmtui -g 50x30+650+150 nmtui") },
  { MODKEY|ControlMask,  XK_Delete,      spawn,    SHCMD("st -c float-st-bpytop -g 120x30+350+200 bpytop") },
  { MODKEY|ShiftMask,    XK_Delete,      spawn,    SHCMD("st -c float-st-gotop -g 100x25+350+200 gotop") },
  { MODKEY|ShiftMask,    XK_r,           spawn,    SHCMD("st -c float-st-gotop -g 100x25+350+200 gotop") },
  /* screenshots */
	{ 0,			     	XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,	  XK_Print,	spawn,		SHCMD("maimpick") },
	{ ControlMask,  XK_Print,	spawn,		SHCMD("ss-cp") },
	{ MODKEY,	      XK_v,    spawn,	    SHCMD("dmenurecord") },

  /*___________________________________________________agstr____________________________________________________ */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_w,      tabmode,        {-1} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { ALTKEY,                       XK_Tab,    swapfocus,      {0} }, 
	{ MODKEY,                       XK_n,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_n,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_g,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_x,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_x,      defaultgaps,    {0} },
	{ MODKEY,                       XK_z,      incrgaps,       {.i = +3 } },
	{ MODKEY|ShiftMask,             XK_z,      incrgaps,       {.i = -3 } },
	{ MODKEY|ControlMask,           XK_i,      incrigaps,      {.i = +3 } },
	{ MODKEY|ControlMask|ShiftMask, XK_i,      incrigaps,      {.i = -3 } },
	{ MODKEY|ControlMask,           XK_o,      incrogaps,      {.i = +3 } },
	{ MODKEY|ControlMask|ShiftMask, XK_o,      incrogaps,      {.i = -3 } },
	{ MODKEY|ALTKEY,                XK_6,      incrihgaps,     {.i = +3 } },
	{ MODKEY|ALTKEY|ShiftMask,      XK_6,      incrihgaps,     {.i = -3 } },
	{ MODKEY|ALTKEY,                XK_7,      incrivgaps,     {.i = +3 } },
	{ MODKEY|ALTKEY|ShiftMask,      XK_7,      incrivgaps,     {.i = -3 } },
	{ MODKEY|ALTKEY,                XK_8,      incrohgaps,     {.i = +3 } },
	{ MODKEY|ALTKEY|ShiftMask,      XK_8,      incrohgaps,     {.i = -3 } },
	{ MODKEY|ALTKEY,                XK_9,      incrovgaps,     {.i = +3 } },
	{ MODKEY|ALTKEY|ShiftMask,      XK_9,      incrovgaps,     {.i = -3 } },
  { MODKEY,                       XK_o,      view_adjacent,  { .i = +1 } },
	{ MODKEY,                       XK_i,      view_adjacent,  { .i = -1 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,   XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,             XK_t,   setlayout,   {.v = &layouts[0]} }, //tile
	{ MODKEY|ShiftMask,   XK_t,   setlayout,   {.v = &layouts[5]} }, //bstack
	{ MODKEY,             XK_y,   setlayout,   {.v = &layouts[9]} }, //horizgrid
	{ MODKEY|ShiftMask,   XK_y,   setlayout,   {.v = &layouts[10]} }, //gaplessgrid
	{ MODKEY,             XK_u,   setlayout,   {.v = &layouts[11]} }, //ceneteredmaster
	{ MODKEY|ShiftMask,   XK_u,   setlayout,   {.v = &layouts[12]} }, //ceneteredfloatingmaster
	{ MODKEY|ShiftMask,   XK_f,   setlayout,   {.v = &layouts[13]} }, //floating
	{ MODKEY,             XK_m,   setlayout,   {.v = &layouts[1]} }, //tile
	{ MODKEY|ShiftMask,   XK_s,   setlayout,   {.v = &layouts[2]} }, //spiral
	{ MODKEY,             XK_c,   setlayout,   {.v = &layouts[4]} }, //deck

	{ MODKEY,               XK_semicolon,  setlayout,  {0} },
	{ MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },
	{ MODKEY,               XK_s,      togglesticky,   {0} },
  { MODKEY,               XK_f,      togglefullscr,  {0} },
	{ MODKEY|ControlMask,   XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|ControlMask,   XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ALTKEY,        XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ALTKEY,        XK_period, tagmon,         {.i = +1 } },
/*{ MODKEY,               XK_0,      view,           {.ui = ~0 } }, */
/*{ MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } }, */
	{ MODKEY|ControlMask,   XK_c, 		 setborderpx,  {.i = +1 } },
	{ MODKEY|ControlMask,   XK_x, 		 setborderpx,  {.i = -1 } },
	{ MODKEY|ControlMask,   XK_z,      setborderpx,  {.i = 0 } },
	TAGKEYS(                XK_1,                      0)
	TAGKEYS(                XK_2,                      1)
	TAGKEYS(                XK_3,                      2)
	TAGKEYS(                XK_4,                      3)
	TAGKEYS(                XK_5,                      4)
	TAGKEYS(                XK_6,                      5)
	TAGKEYS(                XK_7,                      6)
	TAGKEYS(                XK_8,                      7)
	TAGKEYS(                XK_9,                      8)
	{ MODKEY|ShiftMask,     XK_o, scratchpad_show, {0} },
	{ MODKEY|ShiftMask,     XK_i, scratchpad_hide, {0} },
	{ MODKEY|ShiftMask,     XK_minus,scratchpad_remove,{0} },
	{ MODKEY|ControlMask,           XK_q,    quit,     {1} }, //quit
	{ MODKEY|ControlMask|ShiftMask, XK_q,    quit,     {0} }, //restart
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click            event mask    button       function        argument */
	{ ClkLtSymbol,      0,            Button1,     setlayout,      {0} },
	{ ClkLtSymbol,      0,            Button3,     setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,      0,            Button2,     zoom,           {0} },
	{ ClkStatusText,    0,            Button1,     sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,    0,            Button2,     sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,    0,            Button3,     sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,    0,            Button4,     sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,    0,            Button5,     sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,    ShiftMask,    Button1,     sigdwmblocks,   {.i = 6} },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,  MODKEY,    Button1,     moveorplace,    {.i = 1} },
	{ ClkClientWin,  MODKEY,    Button2,     togglefloating, {0} },
	{ ClkClientWin,  MODKEY,    Button3,     resizemouse,    {0} },
	{ ClkClientWin,  MODKEY|ShiftMask, Button1, dragmfact,   {0} },
	{ ClkClientWin,  MODKEY|ShiftMask, Button3, dragcfact,   {0} },
	{ ClkTagBar,     0,         Button1,     view,           {0} },
	{ ClkTagBar,     0,         Button3,     toggleview,     {0} },
	{ ClkTagBar,     MODKEY,    Button1,     tag,            {0} },
	{ ClkTagBar,     MODKEY,    Button3,     toggletag,      {0} },
	{ ClkTabBar,     0,         Button1,     focuswin,       {0} },
  { ClkTagBar,     0,         Button4,     view_adjacent,  { .i = -1 } },
	{ ClkTagBar,     0,         Button5,     view_adjacent,  { .i = +1 } },
};
