/* See LICENSE file for copyright and license details. */

#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 2;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
 	{ "Gimp-2.10",	        NULL,			  NULL,		    1 << 2,	      0,			     -1 },
 	{ "Firefox",            NULL,			  NULL,		    1 << 1,			  0,			     -1 },
  { "Yad",				        NULL,       NULL,       0,            1,           -1 },
	{ "Wine",               NULL,       NULL,       0,            1,           -1 },
	{ "Arandr",             NULL,       NULL,       0,            1,           -1 },
	{ "ksnip",              NULL,       NULL,       0,            1,           -1 },
	{ "Pavucontrol",        NULL,       NULL,       0,            1,           -1 },
	{ "vokoscreen",         NULL,       NULL,       0,            1,           -1 },
	{ "SimpleScreenRecorder",NULL,       NULL,       0,            1,           -1 },
	{ "xdman-Main",         NULL,       NULL,       0,            1,           -1 },
	{ "zoom",               NULL,       NULL,       0,            1,           -1 },
	{ "arandr",             NULL,       NULL,       0,            1,           -1 },
	{ "audacious",          NULL,       NULL,       0,            1,           -1 },
	{ "Dragon",             NULL,       NULL,       0,            1,           -1 },
	{ "firefox",            NULL,       NULL,       1 << 1,       0,           -1 },
  /* floatthings */
  { "float-st",           NULL,       NULL,       0,            1,           -1 },
  { "float-st-ranger",    NULL,       NULL,       0,            1,           -1 },
  { "float-st-calcurse",  NULL,       NULL,       0,            1,           -1 },
  { "float-st-calc",      NULL,       NULL,       0,            1,           -1 },
  { "float-st-ncmpcpp",   NULL,       NULL,       0,            1,           -1 },
  { "float-st-nmtui",     NULL,       NULL,       0,            1,           -1 },
  { "float-st-bpytop",    NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
	{ MODKEY,			          XK_equal,	spawn,		SHCMD("pamixer -i 5; pkill -RTMIN+1 dwmblocks") },
	{ MODKEY,			          XK_minus,	spawn,		SHCMD("pamixer -d 5; pkill -RTMIN+1 dwmblocks") },
  { MODKEY,		            XK_0,   	spawn,		SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -RTMIN+1 dwmblocks") },

    /* mpd control */
 	{ MODKEY,			              XK_p,		        	spawn,		SHCMD("mpc -p 6601 toggle") },
	{ MODKEY,			              XK_comma,	        spawn,		SHCMD("mpc -p 6601 prev") },
	{ MODKEY|ShiftMask,		      XK_comma,	        spawn,		SHCMD("mpc -p 6601 seek 0%") },
	{ MODKEY,			              XK_period,	      spawn,		SHCMD("mpc -p 6601 next") },
	{ MODKEY|ShiftMask,		      XK_period,	      spawn,		SHCMD("mpc -p 6601 repeat") },
	{ MODKEY|ALTKEY,		        XK_period,	      spawn,		SHCMD("mpc -p 6601 random") },
  { MODKEY,			              XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -5") },
	{ MODKEY|ShiftMask,		      XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -30") },
	{ MODKEY,			              XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +5") },
	{ MODKEY|ShiftMask,		      XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +30") },

 	{ MODKEY,		                    	XK_BackSpace,	spawn,		     SHCMD("sysact") },
  { MODKEY,											    XK_Escape,    spawn,	   	   SHCMD("sysact") },
  { MODKEY,           					    XK_g,         spawn,	   	   SHCMD("editconfig") },
	{ ControlMask|ALTKEY,		          XK_l,   	    spawn,		     SHCMD("lock") },
  { MODKEY,           					    XK_x,         spawn,	   	   SHCMD("lock.sh") },
  { MODKEY|ShiftMask,  					    XK_x,         spawn,	   	   SHCMD("betterlockscreen --lock") },
  { MODKEY|ShiftMask,  					    XK_e,         spawn,	   	   SHCMD("pcmanfm") },
	{ MODKEY,			                    XK_grave,	  spawn,	       SHCMD("dmenuunicode") },
	{ MODKEY,			                    XK_a,   	  spawn,	       SHCMD("dunstctl history-pop") },
	{ MODKEY|ShiftMask,		            XK_a,   	  spawn,	       SHCMD("dunstctl close-all") },
	{ MODKEY|ControlMask,		          XK_a,   	  spawn,	       SHCMD("dunstctl close") },
	{ MODKEY|ControlMask,		          XK_m,   	  spawn,	       SHCMD("dmenumount") },
	{ MODKEY|ControlMask|ShiftMask,	  XK_m,   	  spawn,	       SHCMD("dmenuumount") },

  /* floatthings */
  { MODKEY|ShiftMask,    XK_Return,      spawn,    SHCMD("st -c float-st -g 100x25+350+200") },
  { MODKEY,              XK_e,           spawn,    SHCMD("st -c float-st-ranger -g 100x25+350+200 ranger") },
  { MODKEY|ShiftMask,    XK_c,           spawn,    SHCMD("st -c float-st-calcurse -g 100x25+350+200 calcurse") },
  { MODKEY,              XK_apostrophe,  spawn,    SHCMD("st -c float-st-calc -g 50x20+350+200 bc -lq") },
  { MODKEY|ShiftMask,    XK_m,           spawn,    SHCMD("st -c float-st-ncmpcpp -g 100x25+350+200 ncmpcpp") },
  { MODKEY|ControlMask,  XK_n,           spawn,    SHCMD("st -c float-st-nmtui -g 50x30+350+200 nmtui") },
  { MODKEY|ShiftMask,    XK_r,           spawn,    SHCMD("st -c float-st-bpytop -g 100x25+350+200 bpytop") },

  /* screenshots */
	{ 0,			                      	XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,			                XK_Print,	spawn,		SHCMD("maimpick") },
	{ ControlMask,			              XK_Print,	spawn,		SHCMD("ss-cp") },

  /*___________________________________________________agstr____________________________________________________ */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_n,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_n,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_semicolon,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	{ MODKEY|ControlMask,           XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ALTKEY,                XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ALTKEY,                XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

