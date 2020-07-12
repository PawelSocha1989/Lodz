#include "glm.h"

float jas_sw=0.7, xrad, yrad, pod=2, wew=2, wew2=2, obrot_x, obrot_y, obrot_z;

int diffx=0, diffy=0;

TwBar *moj_bar;
GLMmodel* lodz = NULL;
GLMmodel* podl = NULL;
GLMmodel* sceneria = NULL;
GLMmodel* jaskinia = NULL;
GLMmodel* czajnik = NULL;
GLMmodel* komp = NULL;
GLMmodel* komp_s = NULL;

//struktury i zmienne dla wspolrzednych kolizji:
struct boxy
{
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;

};

//boxy kolizji

boxy boxx01={ 70.0, -18.0, 68.0,  89.0, 18.5, 30.0 };
boxy boxx0= { 60.0, -18.0, 70.0,  70.0, 18.5, 30.0 };
boxy boxx1= { 50.0, -18.0, 70.0,  60.0, 18.5, 29.0 };
boxy boxx2= { 40.0, -18.0, 65.0,  50.0, 18.5, 25.0 };
boxy boxx3= { 30.0, -18.0, 60.0,  40.0, 18.5, 22.0 };
boxy boxx4= { 20.0, -18.0, 57.0,  30.0, 18.5, 19.0 };
boxy boxx5= { 10.0, -18.0, 55.0,  20.0, 18.5, 16.0 };
boxy boxx6= {  0.0, -18.0, 55.0,  10.0, 18.5, 13.0 };
boxy boxx7= {-10.0, -18.0, 53.0,   0.0, 18.5,  8.0 };
boxy boxx8= {-20.0, -18.0, 50.0, -10.0, 18.5,  2.0 };
boxy boxx9= {-30.0, -18.0, 40.0, -20.0, 18.5, -5.0 };
boxy boxx10={-40.0, -18.0, 36.0, -30.0, 18.5, -9.0 };
boxy boxx11={-50.0, -18.0, 32.0, -40.0, 18.5, -15.0};
boxy boxx12={-60.0, -18.0, 25.0, -50.0, 18.5, -27.0};
boxy boxx13={-70.0, -18.0, 17.0, -60.0, 18.5, -35.0};
boxy boxx14={-80.0, -18.0, 11.0, -70.0, 18.5, -43.0};
boxy boxx15={-90.0, -18.0,  2.0, -80.0, 18.5, -50.0};
boxy boxx16={-100.0, -18.0, -5.0, -90.0, 18.5, -50.0};
boxy boxx17={-110.0, -18.0, -10.0, -100.0, 18.5,-50.0};


boxy boxx18={ 70.0,  -11.0, 52.0,  89.0,  10.0, 46.0 };
boxy boxx19= { 60.0, -11.0, 54.0,  70.0,  10.0, 46.0 };
boxy boxx20= { 50.0, -11.0, 54.0,  60.0,  10.0, 45.0 };
boxy boxx21= { 40.0, -11.0, 49.0,  50.0,  10.0, 41.0 };
boxy boxx22= { 30.0, -11.0, 44.0,  40.0,  10.0, 38.0 };
boxy boxx23= { 20.0, -11.0, 41.0,  30.0,  10.0, 35.0 };
boxy boxx24= { 10.0, -11.0, 39.0,  20.0,  10.0, 32.0 };
boxy boxx25= {  0.0, -11.0, 39.0,  10.0,  10.0, 29.0 };
boxy boxx26= {-10.0, -11.0, 37.0,   0.0,  10.0, 24.0 };
boxy boxx27= {-20.0, -11.0, 34.0, -10.0,  10.0, 18.0 };
boxy boxx28= {-30.0, -11.0, 34.0, -20.0,  10.0, 11.0 };
boxy boxx29={-40.0,  -11.0, 20.0,  -30.0, 10.0,  7.0 };
boxy boxx30={-50.0,  -11.0, 16.0,  -40.0, 10.0,  1.0 };
boxy boxx31={-60.0,  -11.0,  9.0,  -50.0, 10.0, -10.0};
boxy boxx32={-70.0,  -11.0,  1.0,  -60.0, 10.0, -19.0};
boxy boxx33={-80.0,  -11.0, -5.0,  -70.0, 10.0, -27.0};
boxy boxx34={-90.0,  -11.0, -14.0,  -80.0, 10.0, -34.0};
boxy boxx35={-100.0, -11.0, -21.0, -90.0, 10.0, -34.0};
boxy boxx36={-110.0, -11.0, -26.0,-100.0, 10.0, -34.0};

boxy boxx37={ 70.0, -8.0, 58.0,  89.0,  6,  40.0 };
boxy boxx38= { 60.0, -8.0, 60.0,  70.0, 6, 40.0 };
boxy boxx39= { 50.0, -8.0, 60.0,  60.0, 6, 39.0 };
boxy boxx40= { 40.0, -8.0, 55.0,  50.0, 6, 35.0 };
boxy boxx41= { 30.0, -8.0, 50.0,  40.0, 6, 32.0 };
boxy boxx42= { 20.0, -8.0, 47.0,  30.0, 6, 29.0 };
boxy boxx43= { 10.0, -8.0, 45.0,  20.0, 6, 26.0 };
boxy boxx44= {  0.0, -8.0, 45.0,  10.0, 6, 23.0 };
boxy boxx45= {-10.0, -8.0, 43.0,   0.0, 6, 18.0 };
boxy boxx46= {-20.0, -8.0, 40.0, -10.0, 6, 12.0 };
boxy boxx47= {-30.0, -8.0, 30.0, -20.0, 6,  5.0 };
boxy boxx48={-40.0, -8.0,  26.0, -30.0, 6,  1.0 };
boxy boxx49={-50.0, -8.0,  22.0, -40.0, 6,  0.0};
boxy boxx50={-60.0, -8.0,  20.0, -50.0, 6, -12.0};
boxy boxx51={-70.0, -8.0,   7.0, -60.0, 6, -20.0};
boxy boxx52={-80.0, -8.0,  -4.0, -70.0, 6, -28.0};
boxy boxx53={-90.0, -8.0,  -17.0, -80.0, 6, -35.0};
boxy boxx54={-100.0, -8.0, -22.0, -90.0, 6, -35.0};
boxy boxx55={-110.0, -8.0, -25.0, -100.0, 6,-35.0};

int flaga_boxow=0;


struct Vector3
{
	float x, y, z;
};

struct kamera_trzeciej_osoby
{
	struct Vector3 poz, obr;
	float radian, ost_x, ost_y;
};

struct kamera_trzeciej_osoby camera;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);   
   glEnable(GL_DEPTH_TEST);
   glShadeModel (GL_SMOOTH);

   memset( &camera, 0, sizeof( struct kamera_trzeciej_osoby ) );
   camera.radian = 10.0f;
   camera.poz.x=65.8f;
   camera.poz.y=-1.7f;
   camera.poz.z=79.3f;
   camera.obr.y=-180.0f;
   camera.obr.x=0.0f;
}

void woda(void)
{
    if (!podl) 
	{
        podl = glmReadOBJ((char*)"podloze.obj", 0);	
        if (!podl) exit(0);
        glmUnitize(podl);
		glmScale(podl, 500);
        glmFacetNormals(podl);        
		glmVertexNormals(podl, 90.0);
    }
    glmDraw(podl, GLM_SMOOTH|GLM_TEXTURE);
}

void czajniczek(void)
{
    if (!czajnik) 
	{
        czajnik = glmReadOBJ((char*)"czajnik.obj", 0);	
        if (!czajnik) exit(0);
        glmUnitize(czajnik);
        glmFacetNormals(czajnik);        
		glmVertexNormals(czajnik, 90.0);
    }
    glmDraw(czajnik, GLM_SMOOTH|GLM_COLOR);
}

void cave(void)
{
    if (!jaskinia) 
	{
        jaskinia = glmReadOBJ((char*)"jaskinia.obj", 0);	
        if (!jaskinia) exit(0);
        glmUnitize(jaskinia);
        glmScale(jaskinia, 100);
		glmFacetNormals(jaskinia);        
		glmVertexNormals(jaskinia, 90.0);
    }
    glmDraw(jaskinia, GLM_SMOOTH|GLM_TEXTURE);
}

void kompas(void)
{
    if (!komp) 
	{
        komp = glmReadOBJ((char*)"kompas.obj", 0);	
        if (!komp) exit(0);
        glmUnitize(komp);
		glmScale(komp, 1.3);
        glmFacetNormals(komp);        
		glmVertexNormals(komp, 90.0);
    }
    glmDraw(komp, GLM_SMOOTH|GLM_TEXTURE);
}

void scena(void)
{
    if (!sceneria) 
	{
        sceneria = glmReadOBJ((char*)"sceneria.obj", 0);	
        if (!sceneria) exit(0);
        glmUnitize(sceneria);
		glmScale(sceneria, 500);
        glmFacetNormals(sceneria);        
		glmVertexNormals(sceneria, 90.0);
    }
    glmDraw(sceneria, GLM_SMOOTH|GLM_TEXTURE);
}

void lodka(void)
{
    if (!lodz) 
	{
        lodz = glmReadOBJ((char*)"ludz2.obj", 0);
        if (!lodz) exit(0);
        glmUnitize(lodz);
		glmScale(lodz, 5);
        glmFacetNormals(lodz);        
		glmVertexNormals(lodz, 90.0);
    }
    glmDraw(lodz, GLM_SMOOTH|GLM_TEXTURE);
}

void strzalka(void)
{
    if (!komp_s) 
	{
        komp_s = glmReadOBJ((char*)"strzala.obj", 0);
        if (!komp_s) exit(0);
        glmUnitize(komp_s);
		glmScale(komp_s, 0.9);
        glmFacetNormals(komp_s);        
		glmVertexNormals(komp_s, 90.0);
    }
    glmDraw(komp_s, GLM_SMOOTH|GLM_TEXTURE);
}

void AnT()
{
	moj_bar = TwNewBar("Przybornik");
	TwDefine(" TweakBar size='200 200' color='96 216 224' ");
	
	TwAddVarRW(moj_bar, "Jasnosc", TW_TYPE_FLOAT, &jas_sw, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");
	
	TwAddVarRW(moj_bar, "poz_x", TW_TYPE_FLOAT, &camera.poz.x, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");
	
	TwAddVarRW(moj_bar, "poz_y", TW_TYPE_FLOAT, &camera.poz.y, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");
	
	TwAddVarRW(moj_bar, "poz_z", TW_TYPE_FLOAT, &camera.poz.z, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");

	TwAddVarRW(moj_bar, "obr_y", TW_TYPE_FLOAT, &camera.obr.y, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");

	TwAddVarRW(moj_bar, "obr_x", TW_TYPE_FLOAT, &camera.obr.x, 
        " min=0.1 max=2.5 step=0.1 help='Scale the object (1=original size).' ");

	TwDraw();
}

void komp1()
{
	glPushMatrix();
	glScalef(0.3,0.3,0.3);
	glTranslatef(0,0,-5.75);
	glTranslatef(5.4,0,0);
	glTranslatef(0,-2.07,0);
	glRotatef(120,1,1,1);
	glRotatef(-90,0,1,0);
	kompas();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3,0.3,0.3);
	glTranslatef(0,0,-5.6);
	glTranslatef(5.35,0,0);
	glTranslatef(0,-2.17,0);
	glRotatef(120,1,1,1);
	glRotatef(-90,0,1,0);
	glRotatef(-camera.obr.y, 0.0f, 1.0f, 0.0f);
	strzalka();
	glPopMatrix();

}

void kol()
{
	if(camera.poz.y<=-18) pod=1;
	else if(camera.poz.y>=18.5) pod=0;
	else if((camera.poz.y<=17.5)&&(camera.poz.y>=-17)) pod=2;

	if((camera.poz.y<=-11)||(camera.poz.y>=10)) wew2=2;
	else if((camera.poz.y<=6)&&(camera.poz.y>=-8)) wew2=0;
	else if(((camera.poz.y<=10)&&(camera.poz.y>=6))||
		   ((camera.poz.y<=-8)&&(camera.poz.y>=-11))) wew2=1;

	if(((camera.poz.z<=boxx37.z2)||(camera.poz.z>=boxx37.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx18.z1)&&(camera.poz.z>=boxx18.z2)&&
	        (camera.poz.x<=boxx37.x2)&&(camera.poz.x>=boxx37.x1)) wew=0;
	else if((((camera.poz.z<=boxx18.z2)&&(camera.poz.z>=boxx37.z2))||
	         ((camera.poz.z<=boxx37.z1)&&(camera.poz.z>=boxx18.z1)))&&
			 ((camera.poz.x<=boxx37.x2)&&(camera.poz.x>=boxx37.x1))) wew=1;

	if(((camera.poz.z<=boxx38.z2)||(camera.poz.z>=boxx38.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx19.z1)&&(camera.poz.z>=boxx19.z2)&&
	        (camera.poz.x<=boxx38.x2)&&(camera.poz.x>=boxx38.x1)) wew=0;
	else if((((camera.poz.z<=boxx19.z2)&&(camera.poz.z>=boxx38.z2))||
	         ((camera.poz.z<=boxx38.z1)&&(camera.poz.z>=boxx19.z1)))&&
			 ((camera.poz.x<=boxx38.x2)&&(camera.poz.x>=boxx38.x1))) wew=1;

	if(((camera.poz.z<=boxx39.z2)||(camera.poz.z>=boxx39.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx20.z1)&&(camera.poz.z>=boxx20.z2)&&
	        (camera.poz.x<=boxx39.x2)&&(camera.poz.x>=boxx39.x1)) wew=0;
	else if((((camera.poz.z<=boxx20.z2)&&(camera.poz.z>=boxx39.z2))||
	         ((camera.poz.z<=boxx39.z1)&&(camera.poz.z>=boxx20.z1)))&&
			 ((camera.poz.x<=boxx39.x2)&&(camera.poz.x>=boxx39.x1))) wew=1;

	if(((camera.poz.z<=boxx40.z2)||(camera.poz.z>=boxx40.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx21.z1)&&(camera.poz.z>=boxx21.z2)&&
	        (camera.poz.x<=boxx40.x2)&&(camera.poz.x>=boxx40.x1)) wew=0;
	else if((((camera.poz.z<=boxx21.z2)&&(camera.poz.z>=boxx40.z2))||
	         ((camera.poz.z<=boxx40.z1)&&(camera.poz.z>=boxx21.z1)))&&
			 ((camera.poz.x<=boxx40.x2)&&(camera.poz.x>=boxx40.x1))) wew=1;
			
	if(((camera.poz.z<=boxx41.z2)||(camera.poz.z>=boxx41.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx22.z1)&&(camera.poz.z>=boxx22.z2)&&
	        (camera.poz.x<=boxx41.x2)&&(camera.poz.x>=boxx41.x1)) wew=0;
	else if((((camera.poz.z<=boxx22.z2)&&(camera.poz.z>=boxx41.z2))||
	         ((camera.poz.z<=boxx41.z1)&&(camera.poz.z>=boxx22.z1)))&&
			 ((camera.poz.x<=boxx41.x2)&&(camera.poz.x>=boxx41.x1))) wew=1;
			
	if(((camera.poz.z<=boxx42.z2)||(camera.poz.z>=boxx42.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx23.z1)&&(camera.poz.z>=boxx23.z2)&&
	        (camera.poz.x<=boxx42.x2)&&(camera.poz.x>=boxx42.x1)) wew=0;
	else if((((camera.poz.z<=boxx23.z2)&&(camera.poz.z>=boxx42.z2))||
	         ((camera.poz.z<=boxx42.z1)&&(camera.poz.z>=boxx23.z1)))&&
			 ((camera.poz.x<=boxx42.x2)&&(camera.poz.x>=boxx42.x1))) wew=1;
			
	if(((camera.poz.z<=boxx43.z2)||(camera.poz.z>=boxx43.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx24.z1)&&(camera.poz.z>=boxx24.z2)&&
	        (camera.poz.x<=boxx43.x2)&&(camera.poz.x>=boxx43.x1)) wew=0;
	else if((((camera.poz.z<=boxx24.z2)&&(camera.poz.z>=boxx43.z2))||
	         ((camera.poz.z<=boxx43.z1)&&(camera.poz.z>=boxx24.z1)))&&
			 ((camera.poz.x<=boxx43.x2)&&(camera.poz.x>=boxx43.x1))) wew=1;
			
	if(((camera.poz.z<=boxx44.z2)||(camera.poz.z>=boxx44.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx25.z1)&&(camera.poz.z>=boxx25.z2)&&
	        (camera.poz.x<=boxx44.x2)&&(camera.poz.x>=boxx44.x1)) wew=0;
	else if((((camera.poz.z<=boxx25.z2)&&(camera.poz.z>=boxx44.z2))||
	         ((camera.poz.z<=boxx44.z1)&&(camera.poz.z>=boxx25.z1)))&&
			 ((camera.poz.x<=boxx44.x2)&&(camera.poz.x>=boxx44.x1))) wew=1;
			
	if(((camera.poz.z<=boxx45.z2)||(camera.poz.z>=boxx45.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx26.z1)&&(camera.poz.z>=boxx26.z2)&&
	        (camera.poz.x<=boxx45.x2)&&(camera.poz.x>=boxx45.x1)) wew=0;
	else if((((camera.poz.z<=boxx26.z2)&&(camera.poz.z>=boxx45.z2))||
	         ((camera.poz.z<=boxx45.z1)&&(camera.poz.z>=boxx26.z1)))&&
			 ((camera.poz.x<=boxx45.x2)&&(camera.poz.x>=boxx45.x1))) wew=1;
			
	if(((camera.poz.z<=boxx46.z2)||(camera.poz.z>=boxx46.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx27.z1)&&(camera.poz.z>=boxx27.z2)&&
	        (camera.poz.x<=boxx46.x2)&&(camera.poz.x>=boxx46.x1)) wew=0;
	else if((((camera.poz.z<=boxx27.z2)&&(camera.poz.z>=boxx46.z2))||
	         ((camera.poz.z<=boxx46.z1)&&(camera.poz.z>=boxx27.z1)))&&
			 ((camera.poz.x<=boxx46.x2)&&(camera.poz.x>=boxx46.x1))) wew=1;
			
	if(((camera.poz.z<=boxx47.z2)||(camera.poz.z>=boxx47.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx28.z1)&&(camera.poz.z>=boxx28.z2)&&
	        (camera.poz.x<=boxx47.x2)&&(camera.poz.x>=boxx47.x1)) wew=0;
	else if((((camera.poz.z<=boxx28.z2)&&(camera.poz.z>=boxx47.z2))||
	         ((camera.poz.z<=boxx47.z1)&&(camera.poz.z>=boxx28.z1)))&&
			 ((camera.poz.x<=boxx47.x2)&&(camera.poz.x>=boxx47.x1))) wew=1;
			
	if(((camera.poz.z<=boxx48.z2)||(camera.poz.z>=boxx48.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx29.z1)&&(camera.poz.z>=boxx29.z2)&&
	        (camera.poz.x<=boxx48.x2)&&(camera.poz.x>=boxx48.x1)) wew=0;
	else if((((camera.poz.z<=boxx29.z2)&&(camera.poz.z>=boxx48.z2))||
	         ((camera.poz.z<=boxx48.z1)&&(camera.poz.z>=boxx29.z1)))&&
			 ((camera.poz.x<=boxx48.x2)&&(camera.poz.x>=boxx48.x1))) wew=1;
			
	if(((camera.poz.z<=boxx49.z2)||(camera.poz.z>=boxx49.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx30.z1)&&(camera.poz.z>=boxx30.z2)&&
	        (camera.poz.x<=boxx49.x2)&&(camera.poz.x>=boxx49.x1)) wew=0;
	else if((((camera.poz.z<=boxx30.z2)&&(camera.poz.z>=boxx49.z2))||
	         ((camera.poz.z<=boxx49.z1)&&(camera.poz.z>=boxx30.z1)))&&
			 ((camera.poz.x<=boxx49.x2)&&(camera.poz.x>=boxx49.x1))) wew=1;
			
	if(((camera.poz.z<=boxx50.z2)||(camera.poz.z>=boxx50.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx31.z1)&&(camera.poz.z>=boxx31.z2)&&
	        (camera.poz.x<=boxx50.x2)&&(camera.poz.x>=boxx50.x1)) wew=0;
	else if((((camera.poz.z<=boxx31.z2)&&(camera.poz.z>=boxx50.z2))||
	         ((camera.poz.z<=boxx50.z1)&&(camera.poz.z>=boxx31.z1)))&&
			 ((camera.poz.x<=boxx50.x2)&&(camera.poz.x>=boxx50.x1))) wew=1;
			
	if(((camera.poz.z<=boxx51.z2)||(camera.poz.z>=boxx51.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx32.z1)&&(camera.poz.z>=boxx32.z2)&&
	        (camera.poz.x<=boxx51.x2)&&(camera.poz.x>=boxx51.x1)) wew=0;
	else if((((camera.poz.z<=boxx32.z2)&&(camera.poz.z>=boxx51.z2))||
	         ((camera.poz.z<=boxx51.z1)&&(camera.poz.z>=boxx32.z1)))&&
			 ((camera.poz.x<=boxx51.x2)&&(camera.poz.x>=boxx51.x1))) wew=1;
			
	if(((camera.poz.z<=boxx52.z2)||(camera.poz.z>=boxx52.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx33.z1)&&(camera.poz.z>=boxx33.z2)&&
	        (camera.poz.x<=boxx52.x2)&&(camera.poz.x>=boxx52.x1)) wew=0;
	else if((((camera.poz.z<=boxx33.z2)&&(camera.poz.z>=boxx52.z2))||
	         ((camera.poz.z<=boxx52.z1)&&(camera.poz.z>=boxx33.z1)))&&
			 ((camera.poz.x<=boxx52.x2)&&(camera.poz.x>=boxx52.x1))) wew=1;
			
	if(((camera.poz.z<=boxx53.z2)||(camera.poz.z>=boxx53.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx34.z1)&&(camera.poz.z>=boxx34.z2)&&
	        (camera.poz.x<=boxx53.x2)&&(camera.poz.x>=boxx53.x1)) wew=0;
	else if((((camera.poz.z<=boxx34.z2)&&(camera.poz.z>=boxx53.z2))||
	         ((camera.poz.z<=boxx53.z1)&&(camera.poz.z>=boxx34.z1)))&&
			 ((camera.poz.x<=boxx53.x2)&&(camera.poz.x>=boxx53.x1))) wew=1;
			
	if(((camera.poz.z<=boxx54.z2)||(camera.poz.z>=boxx54.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx35.z1)&&(camera.poz.z>=boxx35.z2)&&
	        (camera.poz.x<=boxx54.x2)&&(camera.poz.x>=boxx54.x1)) wew=0;
	else if((((camera.poz.z<=boxx35.z2)&&(camera.poz.z>=boxx54.z2))||
	         ((camera.poz.z<=boxx54.z1)&&(camera.poz.z>=boxx35.z1)))&&
			 ((camera.poz.x<=boxx54.x2)&&(camera.poz.x>=boxx54.x1))) wew=1;
			
	if(((camera.poz.z<=boxx55.z2)||(camera.poz.z>=boxx55.z1))&&
   ((camera.poz.x<=boxx55.x1)||(camera.poz.x>=boxx37.x2))) wew=2;
	else if((camera.poz.z<=boxx36.z1)&&(camera.poz.z>=boxx36.z2)&&
	        (camera.poz.x<=boxx55.x2)&&(camera.poz.x>=boxx55.x1)) wew=0;
	else if((((camera.poz.z<=boxx36.z2)&&(camera.poz.z>=boxx55.z2))||
	         ((camera.poz.z<=boxx55.z1)&&(camera.poz.z>=boxx36.z1)))&&
			 ((camera.poz.x<=boxx55.x2)&&(camera.poz.x>=boxx55.x1))) wew=1;
}

void kolizje_wew()
{
	//œciana lewa
	if((camera.poz.z<boxx37.z1)&&(camera.poz.z>boxx37.z1-2)&&
	   (camera.poz.x>=boxx37.x1)&&(camera.poz.x<=boxx37.x2)&&
	   (camera.poz.y>=boxx37.y1)&&(camera.poz.y<=boxx37.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx38.z1)&&(camera.poz.z>boxx38.z1-2)&&
	   (camera.poz.x>=boxx38.x1)&&(camera.poz.x<=boxx38.x2)&&
	   (camera.poz.y>=boxx38.y1)&&(camera.poz.y<=boxx38.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx39.z1)&&(camera.poz.z>boxx39.z1-2)&&
	   (camera.poz.x>=boxx39.x1)&&(camera.poz.x<=boxx39.x2)&&
	   (camera.poz.y>=boxx39.y1)&&(camera.poz.y<=boxx39.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx40.z1)&&(camera.poz.z>boxx40.z1-2)&&
	   (camera.poz.x>=boxx40.x1)&&(camera.poz.x<=boxx40.x2)&&
	   (camera.poz.y>=boxx40.y1)&&(camera.poz.y<=boxx40.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx41.z1)&&(camera.poz.z>boxx41.z1-2)&&
	   (camera.poz.x>=boxx41.x1)&&(camera.poz.x<=boxx41.x2)&&
	   (camera.poz.y>=boxx41.y1)&&(camera.poz.y<=boxx41.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx42.z1)&&(camera.poz.z>boxx42.z1-2)&&
	   (camera.poz.x>=boxx42.x1)&&(camera.poz.x<=boxx42.x2)&&
	   (camera.poz.y>=boxx42.y1)&&(camera.poz.y<=boxx42.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx43.z1)&&(camera.poz.z>boxx43.z1-2)&&
	   (camera.poz.x>=boxx43.x1)&&(camera.poz.x<=boxx43.x2)&&
	   (camera.poz.y>=boxx43.y1)&&(camera.poz.y<=boxx43.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx44.z1)&&(camera.poz.z>boxx44.z1-2)&&
	   (camera.poz.x>=boxx44.x1)&&(camera.poz.x<=boxx44.x2)&&
	   (camera.poz.y>=boxx44.y1)&&(camera.poz.y<=boxx44.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx45.z1)&&(camera.poz.z>boxx45.z1-2)&&
	   (camera.poz.x>=boxx45.x1)&&(camera.poz.x<=boxx45.x2)&&
	   (camera.poz.y>=boxx45.y1)&&(camera.poz.y<=boxx45.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx46.z1)&&(camera.poz.z>boxx46.z1-2)&&
	   (camera.poz.x>=boxx46.x1)&&(camera.poz.x<=boxx46.x2)&&
	   (camera.poz.y>=boxx46.y1)&&(camera.poz.y<=boxx46.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx47.z1)&&(camera.poz.z>boxx47.z1-2)&&
	   (camera.poz.x>=boxx47.x1)&&(camera.poz.x<=boxx47.x2)&&
	   (camera.poz.y>=boxx47.y1)&&(camera.poz.y<=boxx47.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx48.z1)&&(camera.poz.z>boxx48.z1-2)&&
	   (camera.poz.x>=boxx48.x1)&&(camera.poz.x<=boxx48.x2)&&
	   (camera.poz.y>=boxx48.y1)&&(camera.poz.y<=boxx48.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx49.z1)&&(camera.poz.z>boxx49.z1-2)&&
	   (camera.poz.x>=boxx49.x1)&&(camera.poz.x<=boxx49.x2)&&
	   (camera.poz.y>=boxx49.y1)&&(camera.poz.y<=boxx49.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx50.z1)&&(camera.poz.z>boxx50.z1-2)&&
	   (camera.poz.x>=boxx50.x1)&&(camera.poz.x<=boxx50.x2)&&
	   (camera.poz.y>=boxx50.y1)&&(camera.poz.y<=boxx50.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx51.z1)&&(camera.poz.z>boxx51.z1-2)&&
	   (camera.poz.x>=boxx51.x1)&&(camera.poz.x<=boxx51.x2)&&
	   (camera.poz.y>=boxx51.y1)&&(camera.poz.y<=boxx51.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx52.z1)&&(camera.poz.z>boxx52.z1-2)&&
	   (camera.poz.x>=boxx52.x1)&&(camera.poz.x<=boxx52.x2)&&
	   (camera.poz.y>=boxx52.y1)&&(camera.poz.y<=boxx52.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx53.z1)&&(camera.poz.z>boxx53.z1-2)&&
	   (camera.poz.x>=boxx53.x1)&&(camera.poz.x<=boxx53.x2)&&
	   (camera.poz.y>=boxx53.y1)&&(camera.poz.y<=boxx53.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx54.z1)&&(camera.poz.z>boxx54.z1-2)&&
	   (camera.poz.x>=boxx54.x1)&&(camera.poz.x<=boxx54.x2)&&
	   (camera.poz.y>=boxx54.y1)&&(camera.poz.y<=boxx54.y2)) camera.poz.z-=1;

	//œciana prawa
	if((camera.poz.z>boxx37.z2)&&(camera.poz.z<boxx37.z2+2)&&
	   (camera.poz.x>=boxx37.x1)&&(camera.poz.x<=boxx37.x2)&&
	   (camera.poz.y>=boxx37.y1)&&(camera.poz.y<=boxx37.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx38.z2)&&(camera.poz.z<boxx38.z2+2)&&
	   (camera.poz.x>=boxx38.x1)&&(camera.poz.x<=boxx38.x2)&&
	   (camera.poz.y>=boxx38.y1)&&(camera.poz.y<=boxx38.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx39.z2)&&(camera.poz.z<boxx39.z2+2)&&
	   (camera.poz.x>=boxx39.x1)&&(camera.poz.x<=boxx39.x2)&&
	   (camera.poz.y>=boxx39.y1)&&(camera.poz.y<=boxx39.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx40.z2)&&(camera.poz.z<boxx40.z2+2)&&
	   (camera.poz.x>=boxx40.x1)&&(camera.poz.x<=boxx40.x2)&&
	   (camera.poz.y>=boxx40.y1)&&(camera.poz.y<=boxx40.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx41.z2)&&(camera.poz.z<boxx41.z2+2)&&
	   (camera.poz.x>=boxx41.x1)&&(camera.poz.x<=boxx41.x2)&&
	   (camera.poz.y>=boxx41.y1)&&(camera.poz.y<=boxx41.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx42.z2)&&(camera.poz.z<boxx42.z2+2)&&
	   (camera.poz.x>=boxx42.x1)&&(camera.poz.x<=boxx42.x2)&&
	   (camera.poz.y>=boxx42.y1)&&(camera.poz.y<=boxx42.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx43.z2)&&(camera.poz.z<boxx43.z2+2)&&
	   (camera.poz.x>=boxx43.x1)&&(camera.poz.x<=boxx43.x2)&&
	   (camera.poz.y>=boxx43.y1)&&(camera.poz.y<=boxx43.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx44.z2)&&(camera.poz.z<boxx44.z2+2)&&
	   (camera.poz.x>=boxx44.x1)&&(camera.poz.x<=boxx44.x2)&&
	   (camera.poz.y>=boxx44.y1)&&(camera.poz.y<=boxx44.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx45.z2)&&(camera.poz.z<boxx45.z2+2)&&
	   (camera.poz.x>=boxx45.x1)&&(camera.poz.x<=boxx45.x2)&&
	   (camera.poz.y>=boxx45.y1)&&(camera.poz.y<=boxx45.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx46.z2)&&(camera.poz.z<boxx46.z2+2)&&
	   (camera.poz.x>=boxx46.x1)&&(camera.poz.x<=boxx46.x2)&&
	   (camera.poz.y>=boxx46.y1)&&(camera.poz.y<=boxx46.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx47.z2)&&(camera.poz.z<boxx47.z2+2)&&
	   (camera.poz.x>=boxx47.x1)&&(camera.poz.x<=boxx47.x2)&&
	   (camera.poz.y>=boxx47.y1)&&(camera.poz.y<=boxx47.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx48.z2)&&(camera.poz.z<boxx48.z2+2)&&
	   (camera.poz.x>=boxx48.x1)&&(camera.poz.x<=boxx48.x2)&&
	   (camera.poz.y>=boxx48.y1)&&(camera.poz.y<=boxx48.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx49.z2)&&(camera.poz.z<boxx49.z2+2)&&
	   (camera.poz.x>=boxx49.x1)&&(camera.poz.x<=boxx49.x2)&&
	   (camera.poz.y>=boxx49.y1)&&(camera.poz.y<=boxx49.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx50.z2)&&(camera.poz.z<boxx50.z2+2)&&
	   (camera.poz.x>=boxx50.x1)&&(camera.poz.x<=boxx50.x2)&&
	   (camera.poz.y>=boxx50.y1)&&(camera.poz.y<=boxx50.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx51.z2)&&(camera.poz.z<boxx51.z2+2)&&
	   (camera.poz.x>=boxx51.x1)&&(camera.poz.x<=boxx51.x2)&&
	   (camera.poz.y>=boxx51.y1)&&(camera.poz.y<=boxx51.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx52.z2)&&(camera.poz.z<boxx52.z2+2)&&
	   (camera.poz.x>=boxx52.x1)&&(camera.poz.x<=boxx52.x2)&&
	   (camera.poz.y>=boxx52.y1)&&(camera.poz.y<=boxx52.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx53.z2)&&(camera.poz.z<boxx53.z2+2)&&
	   (camera.poz.x>=boxx53.x1)&&(camera.poz.x<=boxx53.x2)&&
	   (camera.poz.y>=boxx53.y1)&&(camera.poz.y<=boxx53.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx54.z2)&&(camera.poz.z<boxx54.z2+2)&&
	   (camera.poz.x>=boxx54.x1)&&(camera.poz.x<=boxx54.x2)&&
	   (camera.poz.y>=boxx54.y1)&&(camera.poz.y<=boxx54.y2)) camera.poz.z+=1;

	//œciana górna
	if((camera.poz.y>boxx18.y2)&&
	   (camera.poz.x>=boxx18.x1)&&(camera.poz.x<=boxx18.x2)&&
	   (camera.poz.z<=boxx18.z1)&&(camera.poz.z>=boxx18.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx19.y2)&&
	   (camera.poz.x>=boxx19.x1)&&(camera.poz.x<=boxx19.x2)&&
	   (camera.poz.z<=boxx19.z1)&&(camera.poz.z>=boxx19.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx20.y2)&&
	   (camera.poz.x>=boxx20.x1)&&(camera.poz.x<=boxx20.x2)&&
	   (camera.poz.z<=boxx20.z1)&&(camera.poz.z>=boxx20.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx21.y2)&&
	   (camera.poz.x>=boxx21.x1)&&(camera.poz.x<=boxx21.x2)&&
	   (camera.poz.z<=boxx21.z1)&&(camera.poz.z>=boxx21.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx22.y2)&&
	   (camera.poz.x>=boxx22.x1)&&(camera.poz.x<=boxx22.x2)&&
	   (camera.poz.z<=boxx22.z1)&&(camera.poz.z>=boxx22.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx23.y2)&&
	   (camera.poz.x>=boxx23.x1)&&(camera.poz.x<=boxx23.x2)&&
	   (camera.poz.z<=boxx23.z1)&&(camera.poz.z>=boxx23.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx24.y2)&&
	   (camera.poz.x>=boxx24.x1)&&(camera.poz.x<=boxx24.x2)&&
	   (camera.poz.z<=boxx24.z1)&&(camera.poz.z>=boxx24.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx25.y2)&&
	   (camera.poz.x>=boxx25.x1)&&(camera.poz.x<=boxx25.x2)&&
	   (camera.poz.z<=boxx25.z1)&&(camera.poz.z>=boxx25.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx26.y2)&&
	   (camera.poz.x>=boxx26.x1)&&(camera.poz.x<=boxx26.x2)&&
	   (camera.poz.z<=boxx26.z1)&&(camera.poz.z>=boxx26.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx27.y2)&&
	   (camera.poz.x>=boxx27.x1)&&(camera.poz.x<=boxx27.x2)&&
	   (camera.poz.z<=boxx27.z1)&&(camera.poz.z>=boxx27.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx28.y2)&&
	   (camera.poz.x>=boxx28.x1)&&(camera.poz.x<=boxx28.x2)&&
	   (camera.poz.z<=boxx28.z1)&&(camera.poz.z>=boxx28.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx29.y2)&&
	   (camera.poz.x>=boxx29.x1)&&(camera.poz.x<=boxx29.x2)&&
	   (camera.poz.z<=boxx29.z1)&&(camera.poz.z>=boxx29.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx30.y2)&&
	   (camera.poz.x>=boxx30.x1)&&(camera.poz.x<=boxx30.x2)&&
	   (camera.poz.z<=boxx30.z1)&&(camera.poz.z>=boxx30.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx31.y2)&&
	   (camera.poz.x>=boxx31.x1)&&(camera.poz.x<=boxx31.x2)&&
	   (camera.poz.z<=boxx31.z1)&&(camera.poz.z>=boxx31.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx32.y2)&&
	   (camera.poz.x>=boxx32.x1)&&(camera.poz.x<=boxx32.x2)&&
	   (camera.poz.z<=boxx32.z1)&&(camera.poz.z>=boxx32.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx33.y2)&&
	   (camera.poz.x>=boxx33.x1)&&(camera.poz.x<=boxx33.x2)&&
	   (camera.poz.z<=boxx33.z1)&&(camera.poz.z>=boxx33.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx34.y2)&&
	   (camera.poz.x>=boxx34.x1)&&(camera.poz.x<=boxx34.x2)&&
	   (camera.poz.z<=boxx34.z1)&&(camera.poz.z>=boxx34.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx35.y2)&&
	   (camera.poz.x>=boxx35.x1)&&(camera.poz.x<=boxx35.x2)&&
	   (camera.poz.z<=boxx35.z1)&&(camera.poz.z>=boxx35.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx36.y2)&&
	   (camera.poz.x>=boxx36.x1)&&(camera.poz.x<=boxx36.x2)&&
	   (camera.poz.z<=boxx36.z1)&&(camera.poz.z>=boxx36.z2)) camera.poz.y-=1;
	
	//œciana dolna
	if((camera.poz.y<boxx18.y1)&&
	   (camera.poz.x>=boxx18.x1)&&(camera.poz.x<=boxx18.x2)&&
	   (camera.poz.z<=boxx18.z1)&&(camera.poz.z>=boxx18.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx19.y1)&&
	   (camera.poz.x>=boxx19.x1)&&(camera.poz.x<=boxx19.x2)&&
	   (camera.poz.z<=boxx19.z1)&&(camera.poz.z>=boxx19.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx20.y1)&&
	   (camera.poz.x>=boxx20.x1)&&(camera.poz.x<=boxx20.x2)&&
	   (camera.poz.z<=boxx20.z1)&&(camera.poz.z>=boxx20.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx21.y1)&&
	   (camera.poz.x>=boxx21.x1)&&(camera.poz.x<=boxx21.x2)&&
	   (camera.poz.z<=boxx21.z1)&&(camera.poz.z>=boxx21.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx22.y1)&&
	   (camera.poz.x>=boxx22.x1)&&(camera.poz.x<=boxx22.x2)&&
	   (camera.poz.z<=boxx22.z1)&&(camera.poz.z>=boxx22.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx23.y1)&&
	   (camera.poz.x>=boxx23.x1)&&(camera.poz.x<=boxx23.x2)&&
	   (camera.poz.z<=boxx23.z1)&&(camera.poz.z>=boxx23.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx24.y1)&&
	   (camera.poz.x>=boxx24.x1)&&(camera.poz.x<=boxx24.x2)&&
	   (camera.poz.z<=boxx24.z1)&&(camera.poz.z>=boxx24.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx25.y1)&&
	   (camera.poz.x>=boxx25.x1)&&(camera.poz.x<=boxx25.x2)&&
	   (camera.poz.z<=boxx25.z1)&&(camera.poz.z>=boxx25.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx26.y1)&&
	   (camera.poz.x>=boxx26.x1)&&(camera.poz.x<=boxx26.x2)&&
	   (camera.poz.z<=boxx26.z1)&&(camera.poz.z>=boxx26.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx27.y1)&&
	   (camera.poz.x>=boxx27.x1)&&(camera.poz.x<=boxx27.x2)&&
	   (camera.poz.z<=boxx27.z1)&&(camera.poz.z>=boxx27.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx28.y1)&&
	   (camera.poz.x>=boxx28.x1)&&(camera.poz.x<=boxx28.x2)&&
	   (camera.poz.z<=boxx28.z1)&&(camera.poz.z>=boxx28.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx29.y1)&&
	   (camera.poz.x>=boxx29.x1)&&(camera.poz.x<=boxx29.x2)&&
	   (camera.poz.z<=boxx29.z1)&&(camera.poz.z>=boxx29.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx30.y1)&&
	   (camera.poz.x>=boxx30.x1)&&(camera.poz.x<=boxx30.x2)&&
	   (camera.poz.z<=boxx30.z1)&&(camera.poz.z>=boxx30.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx31.y1)&&
	   (camera.poz.x>=boxx31.x1)&&(camera.poz.x<=boxx31.x2)&&
	   (camera.poz.z<=boxx31.z1)&&(camera.poz.z>=boxx31.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx32.y1)&&
	   (camera.poz.x>=boxx32.x1)&&(camera.poz.x<=boxx32.x2)&&
	   (camera.poz.z<=boxx32.z1)&&(camera.poz.z>=boxx32.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx33.y1)&&
	   (camera.poz.x>=boxx33.x1)&&(camera.poz.x<=boxx33.x2)&&
	   (camera.poz.z<=boxx33.z1)&&(camera.poz.z>=boxx33.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx34.y1)&&
	   (camera.poz.x>=boxx34.x1)&&(camera.poz.x<=boxx34.x2)&&
	   (camera.poz.z<=boxx34.z1)&&(camera.poz.z>=boxx34.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx35.y1)&&
	   (camera.poz.x>=boxx35.x1)&&(camera.poz.x<=boxx35.x2)&&
	   (camera.poz.z<=boxx35.z1)&&(camera.poz.z>=boxx35.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx36.y1)&&
	   (camera.poz.x>=boxx36.x1)&&(camera.poz.x<=boxx36.x2)&&
	   (camera.poz.z<=boxx36.z1)&&(camera.poz.z>=boxx36.z2)) camera.poz.y+=1;

	//kolejna czêœæ œciany górnej
	if((camera.poz.y>boxx37.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx37.x1)&&(camera.poz.x<=boxx37.x2)&&
	   (camera.poz.z<=boxx37.z1)&&(camera.poz.z>=boxx37.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx38.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx38.x1)&&(camera.poz.x<=boxx38.x2)&&
	   (camera.poz.z<=boxx38.z1)&&(camera.poz.z>=boxx38.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx39.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx39.x1)&&(camera.poz.x<=boxx39.x2)&&
	   (camera.poz.z<=boxx39.z1)&&(camera.poz.z>=boxx39.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx40.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx40.x1)&&(camera.poz.x<=boxx40.x2)&&
	   (camera.poz.z<=boxx40.z1)&&(camera.poz.z>=boxx40.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx41.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx41.x1)&&(camera.poz.x<=boxx41.x2)&&
	   (camera.poz.z<=boxx41.z1)&&(camera.poz.z>=boxx41.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx42.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx42.x1)&&(camera.poz.x<=boxx42.x2)&&
	   (camera.poz.z<=boxx42.z1)&&(camera.poz.z>=boxx42.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx43.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx43.x1)&&(camera.poz.x<=boxx43.x2)&&
	   (camera.poz.z<=boxx43.z1)&&(camera.poz.z>=boxx43.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx44.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx44.x1)&&(camera.poz.x<=boxx44.x2)&&
	   (camera.poz.z<=boxx44.z1)&&(camera.poz.z>=boxx44.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx45.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx45.x1)&&(camera.poz.x<=boxx45.x2)&&
	   (camera.poz.z<=boxx45.z1)&&(camera.poz.z>=boxx45.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx46.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx46.x1)&&(camera.poz.x<=boxx46.x2)&&
	   (camera.poz.z<=boxx46.z1)&&(camera.poz.z>=boxx46.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx47.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx47.x1)&&(camera.poz.x<=boxx47.x2)&&
	   (camera.poz.z<=boxx47.z1)&&(camera.poz.z>=boxx47.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx48.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx48.x1)&&(camera.poz.x<=boxx48.x2)&&
	   (camera.poz.z<=boxx48.z1)&&(camera.poz.z>=boxx48.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx49.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx49.x1)&&(camera.poz.x<=boxx49.x2)&&
	   (camera.poz.z<=boxx49.z1)&&(camera.poz.z>=boxx49.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx50.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx50.x1)&&(camera.poz.x<=boxx50.x2)&&
	   (camera.poz.z<=boxx50.z1)&&(camera.poz.z>=boxx50.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx51.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx51.x1)&&(camera.poz.x<=boxx51.x2)&&
	   (camera.poz.z<=boxx51.z1)&&(camera.poz.z>=boxx51.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx52.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx52.x1)&&(camera.poz.x<=boxx52.x2)&&
	   (camera.poz.z<=boxx52.z1)&&(camera.poz.z>=boxx52.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx53.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx53.x1)&&(camera.poz.x<=boxx53.x2)&&
	   (camera.poz.z<=boxx53.z1)&&(camera.poz.z>=boxx53.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx54.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx54.x1)&&(camera.poz.x<=boxx54.x2)&&
	   (camera.poz.z<=boxx54.z1)&&(camera.poz.z>=boxx54.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx55.y2)&&(wew==1)&&
	   (camera.poz.x>=boxx55.x1)&&(camera.poz.x<=boxx55.x2)&&
	   (camera.poz.z<=boxx55.z1)&&(camera.poz.z>=boxx55.z2)) camera.poz.y-=1;
	
	//kolejna czêœæ œciany dolnej
	if((camera.poz.y<boxx37.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx37.x1)&&(camera.poz.x<=boxx37.x2)&&
	   (camera.poz.z<=boxx37.z1)&&(camera.poz.z>=boxx37.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx38.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx38.x1)&&(camera.poz.x<=boxx38.x2)&&
	   (camera.poz.z<=boxx38.z1)&&(camera.poz.z>=boxx38.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx39.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx39.x1)&&(camera.poz.x<=boxx39.x2)&&
	   (camera.poz.z<=boxx39.z1)&&(camera.poz.z>=boxx39.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx40.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx40.x1)&&(camera.poz.x<=boxx40.x2)&&
	   (camera.poz.z<=boxx40.z1)&&(camera.poz.z>=boxx40.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx41.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx41.x1)&&(camera.poz.x<=boxx41.x2)&&
	   (camera.poz.z<=boxx41.z1)&&(camera.poz.z>=boxx41.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx42.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx42.x1)&&(camera.poz.x<=boxx42.x2)&&
	   (camera.poz.z<=boxx42.z1)&&(camera.poz.z>=boxx42.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx43.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx43.x1)&&(camera.poz.x<=boxx43.x2)&&
	   (camera.poz.z<=boxx43.z1)&&(camera.poz.z>=boxx43.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx44.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx44.x1)&&(camera.poz.x<=boxx44.x2)&&
	   (camera.poz.z<=boxx44.z1)&&(camera.poz.z>=boxx44.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx45.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx45.x1)&&(camera.poz.x<=boxx45.x2)&&
	   (camera.poz.z<=boxx45.z1)&&(camera.poz.z>=boxx45.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx46.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx46.x1)&&(camera.poz.x<=boxx46.x2)&&
	   (camera.poz.z<=boxx46.z1)&&(camera.poz.z>=boxx46.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx47.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx47.x1)&&(camera.poz.x<=boxx47.x2)&&
	   (camera.poz.z<=boxx47.z1)&&(camera.poz.z>=boxx47.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx48.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx48.x1)&&(camera.poz.x<=boxx48.x2)&&
	   (camera.poz.z<=boxx48.z1)&&(camera.poz.z>=boxx48.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx49.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx49.x1)&&(camera.poz.x<=boxx49.x2)&&
	   (camera.poz.z<=boxx49.z1)&&(camera.poz.z>=boxx49.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx50.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx50.x1)&&(camera.poz.x<=boxx50.x2)&&
	   (camera.poz.z<=boxx50.z1)&&(camera.poz.z>=boxx50.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx51.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx51.x1)&&(camera.poz.x<=boxx51.x2)&&
	   (camera.poz.z<=boxx51.z1)&&(camera.poz.z>=boxx51.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx52.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx52.x1)&&(camera.poz.x<=boxx52.x2)&&
	   (camera.poz.z<=boxx52.z1)&&(camera.poz.z>=boxx52.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx53.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx53.x1)&&(camera.poz.x<=boxx53.x2)&&
	   (camera.poz.z<=boxx53.z1)&&(camera.poz.z>=boxx53.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx54.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx54.x1)&&(camera.poz.x<=boxx54.x2)&&
	   (camera.poz.z<=boxx54.z1)&&(camera.poz.z>=boxx54.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx55.y1)&&(wew==1)&&
	   (camera.poz.x>=boxx55.x1)&&(camera.poz.x<=boxx55.x2)&&
	   (camera.poz.z<=boxx55.z1)&&(camera.poz.z>=boxx55.z2)) camera.poz.y+=1;

	//kolejna czêœæ lewej œciany
	if((camera.poz.z<boxx18.z1)&&(camera.poz.z>boxx18.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx18.x1)&&(camera.poz.x<=boxx18.x2)&&
	   (camera.poz.y>=boxx18.y1)&&(camera.poz.y<=boxx18.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx19.z1)&&(camera.poz.z>boxx19.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx19.x1)&&(camera.poz.x<=boxx19.x2)&&
	   (camera.poz.y>=boxx19.y1)&&(camera.poz.y<=boxx19.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx20.z1)&&(camera.poz.z>boxx20.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx20.x1)&&(camera.poz.x<=boxx20.x2)&&
	   (camera.poz.y>=boxx20.y1)&&(camera.poz.y<=boxx20.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx21.z1)&&(camera.poz.z>boxx21.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx21.x1)&&(camera.poz.x<=boxx21.x2)&&
	   (camera.poz.y>=boxx21.y1)&&(camera.poz.y<=boxx21.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx22.z1)&&(camera.poz.z>boxx22.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx22.x1)&&(camera.poz.x<=boxx22.x2)&&
	   (camera.poz.y>=boxx22.y1)&&(camera.poz.y<=boxx22.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx23.z1)&&(camera.poz.z>boxx23.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx23.x1)&&(camera.poz.x<=boxx23.x2)&&
	   (camera.poz.y>=boxx23.y1)&&(camera.poz.y<=boxx23.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx24.z1)&&(camera.poz.z>boxx24.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx24.x1)&&(camera.poz.x<=boxx24.x2)&&
	   (camera.poz.y>=boxx24.y1)&&(camera.poz.y<=boxx24.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx25.z1)&&(camera.poz.z>boxx25.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx25.x1)&&(camera.poz.x<=boxx25.x2)&&
	   (camera.poz.y>=boxx25.y1)&&(camera.poz.y<=boxx25.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx26.z1)&&(camera.poz.z>boxx26.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx26.x1)&&(camera.poz.x<=boxx26.x2)&&
	   (camera.poz.y>=boxx26.y1)&&(camera.poz.y<=boxx26.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx27.z1)&&(camera.poz.z>boxx27.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx27.x1)&&(camera.poz.x<=boxx27.x2)&&
	   (camera.poz.y>=boxx27.y1)&&(camera.poz.y<=boxx27.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx28.z1)&&(camera.poz.z>boxx28.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx28.x1)&&(camera.poz.x<=boxx28.x2)&&
	   (camera.poz.y>=boxx28.y1)&&(camera.poz.y<=boxx28.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx29.z1)&&(camera.poz.z>boxx29.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx29.x1)&&(camera.poz.x<=boxx29.x2)&&
	   (camera.poz.y>=boxx29.y1)&&(camera.poz.y<=boxx29.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx30.z1)&&(camera.poz.z>boxx30.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx30.x1)&&(camera.poz.x<=boxx30.x2)&&
	   (camera.poz.y>=boxx30.y1)&&(camera.poz.y<=boxx30.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx31.z1)&&(camera.poz.z>boxx31.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx31.x1)&&(camera.poz.x<=boxx31.x2)&&
	   (camera.poz.y>=boxx31.y1)&&(camera.poz.y<=boxx31.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx32.z1)&&(camera.poz.z>boxx32.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx32.x1)&&(camera.poz.x<=boxx32.x2)&&
	   (camera.poz.y>=boxx32.y1)&&(camera.poz.y<=boxx32.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx33.z1)&&(camera.poz.z>boxx33.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx33.x1)&&(camera.poz.x<=boxx33.x2)&&
	   (camera.poz.y>=boxx33.y1)&&(camera.poz.y<=boxx33.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx34.z1)&&(camera.poz.z>boxx34.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx34.x1)&&(camera.poz.x<=boxx34.x2)&&
	   (camera.poz.y>=boxx34.y1)&&(camera.poz.y<=boxx34.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx35.z1)&&(camera.poz.z>boxx35.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx35.x1)&&(camera.poz.x<=boxx35.x2)&&
	   (camera.poz.y>=boxx35.y1)&&(camera.poz.y<=boxx35.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx36.z1)&&(camera.poz.z>boxx36.z1-2)&&(wew2==1)&&
	   (camera.poz.x>=boxx36.x1)&&(camera.poz.x<=boxx36.x2)&&
	   (camera.poz.y>=boxx36.y1)&&(camera.poz.y<=boxx36.y2)) camera.poz.z-=1;

	//kolejna czêœæ prawej œciany
	if((camera.poz.z>boxx18.z2)&&(camera.poz.z<boxx18.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx18.x1)&&(camera.poz.x<=boxx18.x2)&&
	   (camera.poz.y>=boxx18.y1)&&(camera.poz.y<=boxx18.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx19.z2)&&(camera.poz.z<boxx19.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx19.x1)&&(camera.poz.x<=boxx19.x2)&&
	   (camera.poz.y>=boxx19.y1)&&(camera.poz.y<=boxx19.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx20.z2)&&(camera.poz.z<boxx20.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx20.x1)&&(camera.poz.x<=boxx20.x2)&&
	   (camera.poz.y>=boxx20.y1)&&(camera.poz.y<=boxx20.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx21.z2)&&(camera.poz.z<boxx21.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx21.x1)&&(camera.poz.x<=boxx21.x2)&&
	   (camera.poz.y>=boxx21.y1)&&(camera.poz.y<=boxx21.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx22.z2)&&(camera.poz.z<boxx22.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx22.x1)&&(camera.poz.x<=boxx22.x2)&&
	   (camera.poz.y>=boxx22.y1)&&(camera.poz.y<=boxx22.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx23.z2)&&(camera.poz.z<boxx23.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx23.x1)&&(camera.poz.x<=boxx23.x2)&&
	   (camera.poz.y>=boxx23.y1)&&(camera.poz.y<=boxx23.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx24.z2)&&(camera.poz.z<boxx24.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx24.x1)&&(camera.poz.x<=boxx24.x2)&&
	   (camera.poz.y>=boxx24.y1)&&(camera.poz.y<=boxx24.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx25.z2)&&(camera.poz.z<boxx25.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx25.x1)&&(camera.poz.x<=boxx25.x2)&&
	   (camera.poz.y>=boxx25.y1)&&(camera.poz.y<=boxx25.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx26.z2)&&(camera.poz.z<boxx26.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx26.x1)&&(camera.poz.x<=boxx26.x2)&&
	   (camera.poz.y>=boxx26.y1)&&(camera.poz.y<=boxx26.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx27.z2)&&(camera.poz.z<boxx27.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx27.x1)&&(camera.poz.x<=boxx27.x2)&&
	   (camera.poz.y>=boxx27.y1)&&(camera.poz.y<=boxx27.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx28.z2)&&(camera.poz.z<boxx28.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx28.x1)&&(camera.poz.x<=boxx28.x2)&&
	   (camera.poz.y>=boxx28.y1)&&(camera.poz.y<=boxx28.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx29.z2)&&(camera.poz.z<boxx29.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx29.x1)&&(camera.poz.x<=boxx29.x2)&&
	   (camera.poz.y>=boxx29.y1)&&(camera.poz.y<=boxx29.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx30.z2)&&(camera.poz.z<boxx30.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx30.x1)&&(camera.poz.x<=boxx30.x2)&&
	   (camera.poz.y>=boxx30.y1)&&(camera.poz.y<=boxx30.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx31.z2)&&(camera.poz.z<boxx31.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx31.x1)&&(camera.poz.x<=boxx31.x2)&&
	   (camera.poz.y>=boxx31.y1)&&(camera.poz.y<=boxx31.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx32.z2)&&(camera.poz.z<boxx32.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx32.x1)&&(camera.poz.x<=boxx32.x2)&&
	   (camera.poz.y>=boxx32.y1)&&(camera.poz.y<=boxx32.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx33.z2)&&(camera.poz.z<boxx33.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx33.x1)&&(camera.poz.x<=boxx33.x2)&&
	   (camera.poz.y>=boxx33.y1)&&(camera.poz.y<=boxx33.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx34.z2)&&(camera.poz.z<boxx34.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx34.x1)&&(camera.poz.x<=boxx34.x2)&&
	   (camera.poz.y>=boxx34.y1)&&(camera.poz.y<=boxx34.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx35.z2)&&(camera.poz.z<boxx35.z2+2)&&(wew2==1)&&
	   (camera.poz.x>=boxx35.x1)&&(camera.poz.x<=boxx35.x2)&&
	   (camera.poz.y>=boxx35.y1)&&(camera.poz.y<=boxx35.y2)) camera.poz.z+=1;
}

void kolizje()
{
	//œciana lewa
	if((camera.poz.z>boxx01.z1)&&(camera.poz.z<boxx01.z1+2)&&
	   (camera.poz.x>=boxx01.x1)&&(camera.poz.x<=boxx01.x2)&&
	   (camera.poz.y>=boxx01.y1)&&(camera.poz.y<=boxx01.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx0.z1)&&(camera.poz.z<boxx0.z1+2)&&
	   (camera.poz.x>=boxx0.x1)&&(camera.poz.x<=boxx0.x2)&&
	   (camera.poz.y>=boxx0.y1)&&(camera.poz.y<=boxx0.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx1.z1)&&(camera.poz.z<boxx1.z1+2)&&
	   (camera.poz.x>=boxx1.x1)&&(camera.poz.x<=boxx1.x2)&&
	   (camera.poz.y>=boxx1.y1)&&(camera.poz.y<=boxx1.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx2.z1)&&(camera.poz.z<boxx2.z1+2)&&
	   (camera.poz.x>=boxx2.x1)&&(camera.poz.x<=boxx2.x2)&&
	   (camera.poz.y>=boxx2.y1)&&(camera.poz.y<=boxx2.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx3.z1)&&(camera.poz.z<boxx3.z1+2)&&
	   (camera.poz.x>=boxx3.x1)&&(camera.poz.x<=boxx3.x2)&&
	   (camera.poz.y>=boxx3.y1)&&(camera.poz.y<=boxx3.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx4.z1)&&(camera.poz.z<boxx4.z1+2)&&
	   (camera.poz.x>=boxx4.x1)&&(camera.poz.x<=boxx4.x2)&&
	   (camera.poz.y>=boxx4.y1)&&(camera.poz.y<=boxx4.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx5.z1)&&(camera.poz.z<boxx5.z1+2)&&
	   (camera.poz.x>=boxx5.x1)&&(camera.poz.x<=boxx5.x2)&&
	   (camera.poz.y>=boxx5.y1)&&(camera.poz.y<=boxx5.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx6.z1)&&(camera.poz.z<boxx6.z1+2)&&
	   (camera.poz.x>=boxx6.x1)&&(camera.poz.x<=boxx6.x2)&&
	   (camera.poz.y>=boxx6.y1)&&(camera.poz.y<=boxx6.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx7.z1)&&(camera.poz.z<boxx7.z1+2)&&
	   (camera.poz.x>=boxx7.x1)&&(camera.poz.x<=boxx7.x2)&&
	   (camera.poz.y>=boxx7.y1)&&(camera.poz.y<=boxx7.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx8.z1)&&(camera.poz.z<boxx8.z1+2)&&
	   (camera.poz.x>=boxx8.x1)&&(camera.poz.x<=boxx8.x2)&&
	   (camera.poz.y>=boxx8.y1)&&(camera.poz.y<=boxx8.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx9.z1)&&(camera.poz.z<boxx9.z1+2)&&
	   (camera.poz.x>=boxx9.x1)&&(camera.poz.x<=boxx9.x2)&&
	   (camera.poz.y>=boxx9.y1)&&(camera.poz.y<=boxx9.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx10.z1)&&(camera.poz.z<boxx10.z1+2)&&
	   (camera.poz.x>=boxx10.x1)&&(camera.poz.x<=boxx10.x2)&&
	   (camera.poz.y>=boxx10.y1)&&(camera.poz.y<=boxx10.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx11.z1)&&(camera.poz.z<boxx11.z1+2)&&
	   (camera.poz.x>=boxx11.x1)&&(camera.poz.x<=boxx11.x2)&&
	   (camera.poz.y>=boxx11.y1)&&(camera.poz.y<=boxx11.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx12.z1)&&(camera.poz.z<boxx12.z1+2)&&
	   (camera.poz.x>=boxx12.x1)&&(camera.poz.x<=boxx12.x2)&&
	   (camera.poz.y>=boxx12.y1)&&(camera.poz.y<=boxx12.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx13.z1)&&(camera.poz.z<boxx13.z1+2)&&
	   (camera.poz.x>=boxx13.x1)&&(camera.poz.x<=boxx13.x2)&&
	   (camera.poz.y>=boxx13.y1)&&(camera.poz.y<=boxx13.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx14.z1)&&(camera.poz.z<boxx14.z1+2)&&
	   (camera.poz.x>=boxx14.x1)&&(camera.poz.x<=boxx14.x2)&&
	   (camera.poz.y>=boxx14.y1)&&(camera.poz.y<=boxx14.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx15.z1)&&(camera.poz.z<boxx15.z1+2)&&
	   (camera.poz.x>=boxx15.x1)&&(camera.poz.x<=boxx15.x2)&&
	   (camera.poz.y>=boxx15.y1)&&(camera.poz.y<=boxx15.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx16.z1)&&(camera.poz.z<boxx16.z1+2)&&
	   (camera.poz.x>=boxx16.x1)&&(camera.poz.x<=boxx16.x2)&&
	   (camera.poz.y>=boxx16.y1)&&(camera.poz.y<=boxx16.y2)) camera.poz.z+=1;

	if((camera.poz.z>boxx17.z1)&&(camera.poz.z<boxx17.z1+2)&&
	   (camera.poz.x>=boxx17.x1)&&(camera.poz.x<=boxx17.x2)&&
	   (camera.poz.y>=boxx17.y1)&&(camera.poz.y<=boxx17.y2)) camera.poz.z+=1;

	//œciana prawa
	if((camera.poz.z<boxx01.z2)&&(camera.poz.z>boxx01.z2-2)&&
	   (camera.poz.x>=boxx01.x1)&&(camera.poz.x<=boxx01.x2)&&
	   (camera.poz.y>=boxx01.y1)&&(camera.poz.y<=boxx01.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx0.z2)&&(camera.poz.z>boxx0.z2-2)&&
	   (camera.poz.x>=boxx0.x1)&&(camera.poz.x<=boxx0.x2)&&
	   (camera.poz.y>=boxx0.y1)&&(camera.poz.y<=boxx0.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx1.z2)&&(camera.poz.z>boxx1.z2-2)&&
	   (camera.poz.x>=boxx1.x1)&&(camera.poz.x<=boxx1.x2)&&
	   (camera.poz.y>=boxx1.y1)&&(camera.poz.y<=boxx1.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx2.z2)&&(camera.poz.z>boxx2.z2-2)&&
	   (camera.poz.x>=boxx2.x1)&&(camera.poz.x<=boxx2.x2)&&
	   (camera.poz.y>=boxx2.y1)&&(camera.poz.y<=boxx2.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx3.z2)&&(camera.poz.z>boxx3.z2-2)&&
	   (camera.poz.x>=boxx3.x1)&&(camera.poz.x<=boxx3.x2)&&
	   (camera.poz.y>=boxx3.y1)&&(camera.poz.y<=boxx3.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx4.z2)&&(camera.poz.z>boxx4.z2-2)&&
	   (camera.poz.x>=boxx4.x1)&&(camera.poz.x<=boxx4.x2)&&
	   (camera.poz.y>=boxx4.y1)&&(camera.poz.y<=boxx4.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx5.z2)&&(camera.poz.z>boxx5.z2-2)&&
	   (camera.poz.x>=boxx5.x1)&&(camera.poz.x<=boxx5.x2)&&
	   (camera.poz.y>=boxx5.y1)&&(camera.poz.y<=boxx5.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx6.z2)&&(camera.poz.z>boxx6.z2-2)&&
	   (camera.poz.x>=boxx6.x1)&&(camera.poz.x<=boxx6.x2)&&
	   (camera.poz.y>=boxx6.y1)&&(camera.poz.y<=boxx6.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx7.z2)&&(camera.poz.z>boxx7.z2-2)&&
	   (camera.poz.x>=boxx7.x1)&&(camera.poz.x<=boxx7.x2)&&
	   (camera.poz.y>=boxx7.y1)&&(camera.poz.y<=boxx7.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx8.z2)&&(camera.poz.z>boxx8.z2-2)&&
	   (camera.poz.x>=boxx8.x1)&&(camera.poz.x<=boxx8.x2)&&
	   (camera.poz.y>=boxx8.y1)&&(camera.poz.y<=boxx8.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx9.z2)&&(camera.poz.z>boxx9.z2-2)&&
	   (camera.poz.x>=boxx9.x1)&&(camera.poz.x<=boxx9.x2)&&
	   (camera.poz.y>=boxx9.y1)&&(camera.poz.y<=boxx9.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx10.z2)&&(camera.poz.z>boxx10.z2-2)&&
	   (camera.poz.x>=boxx10.x1)&&(camera.poz.x<=boxx10.x2)&&
	   (camera.poz.y>=boxx10.y1)&&(camera.poz.y<=boxx10.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx11.z2)&&(camera.poz.z>boxx11.z2-2)&&
	   (camera.poz.x>=boxx11.x1)&&(camera.poz.x<=boxx11.x2)&&
	   (camera.poz.y>=boxx11.y1)&&(camera.poz.y<=boxx11.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx12.z2)&&(camera.poz.z>boxx12.z2-2)&&
	   (camera.poz.x>=boxx12.x1)&&(camera.poz.x<=boxx12.x2)&&
	   (camera.poz.y>=boxx12.y1)&&(camera.poz.y<=boxx12.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx13.z2)&&(camera.poz.z>boxx13.z2-2)&&
	   (camera.poz.x>=boxx13.x1)&&(camera.poz.x<=boxx13.x2)&&
	   (camera.poz.y>=boxx13.y1)&&(camera.poz.y<=boxx13.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx14.z2)&&(camera.poz.z>boxx14.z2-2)&&
	   (camera.poz.x>=boxx14.x1)&&(camera.poz.x<=boxx14.x2)&&
	   (camera.poz.y>=boxx14.y1)&&(camera.poz.y<=boxx14.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx15.z2)&&(camera.poz.z>boxx15.z2-2)&&
	   (camera.poz.x>=boxx15.x1)&&(camera.poz.x<=boxx15.x2)&&
	   (camera.poz.y>=boxx15.y1)&&(camera.poz.y<=boxx15.y2)) camera.poz.z-=1;

	if((camera.poz.z<boxx16.z2)&&(camera.poz.z>boxx16.z2-2)&&
	   (camera.poz.x>=boxx16.x1)&&(camera.poz.x<=boxx16.x2)&&
	   (camera.poz.y>=boxx16.y1)&&(camera.poz.y<=boxx16.y2)) camera.poz.z-=1;

	//œciana górna
	if((camera.poz.y<boxx01.y2)&&(camera.poz.y>boxx01.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx01.x1)&&(camera.poz.x<=boxx01.x2)&&
	   (camera.poz.z<=boxx01.z1)&&(camera.poz.z>=boxx01.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx0.y2)&&(camera.poz.y>boxx0.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx0.x1)&&(camera.poz.x<=boxx0.x2)&&
	   (camera.poz.z<=boxx0.z1)&&(camera.poz.z>=boxx0.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx1.y2)&&(camera.poz.y>boxx1.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx1.x1)&&(camera.poz.x<=boxx1.x2)&&
	   (camera.poz.z<=boxx1.z1)&&(camera.poz.z>=boxx1.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx2.y2)&&(camera.poz.y>boxx2.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx2.x1)&&(camera.poz.x<=boxx2.x2)&&
	   (camera.poz.z<=boxx2.z1)&&(camera.poz.z>=boxx2.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx3.y2)&&(camera.poz.y>boxx3.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx3.x1)&&(camera.poz.x<=boxx3.x2)&&
	   (camera.poz.z<=boxx3.z1)&&(camera.poz.z>=boxx3.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx4.y2)&&(camera.poz.y>boxx4.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx4.x1)&&(camera.poz.x<=boxx4.x2)&&
	   (camera.poz.z<=boxx4.z1)&&(camera.poz.z>=boxx4.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx5.y2)&&(camera.poz.y>boxx5.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx5.x1)&&(camera.poz.x<=boxx5.x2)&&
	   (camera.poz.z<=boxx5.z1)&&(camera.poz.z>=boxx5.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx6.y2)&&(camera.poz.y>boxx6.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx6.x1)&&(camera.poz.x<=boxx6.x2)&&
	   (camera.poz.z<=boxx6.z1)&&(camera.poz.z>=boxx6.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx7.y2)&&(camera.poz.y>boxx7.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx7.x1)&&(camera.poz.x<=boxx7.x2)&&
	   (camera.poz.z<=boxx7.z1)&&(camera.poz.z>=boxx7.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx8.y2)&&(camera.poz.y>boxx8.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx8.x1)&&(camera.poz.x<=boxx8.x2)&&
	   (camera.poz.z<=boxx8.z1)&&(camera.poz.z>=boxx8.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx9.y2)&&(camera.poz.y>boxx9.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx9.x1)&&(camera.poz.x<=boxx9.x2)&&
	   (camera.poz.z<=boxx9.z1)&&(camera.poz.z>=boxx9.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx10.y2)&&(camera.poz.y>boxx10.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx10.x1)&&(camera.poz.x<=boxx10.x2)&&
	   (camera.poz.z<=boxx10.z1)&&(camera.poz.z>=boxx10.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx11.y2)&&(camera.poz.y>boxx11.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx11.x1)&&(camera.poz.x<=boxx11.x2)&&
	   (camera.poz.z<=boxx11.z1)&&(camera.poz.z>=boxx11.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx12.y2)&&(camera.poz.y>boxx12.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx12.x1)&&(camera.poz.x<=boxx12.x2)&&
	   (camera.poz.z<=boxx12.z1)&&(camera.poz.z>=boxx12.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx13.y2)&&(camera.poz.y>boxx13.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx13.x1)&&(camera.poz.x<=boxx13.x2)&&
	   (camera.poz.z<=boxx13.z1)&&(camera.poz.z>=boxx13.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx14.y2)&&(camera.poz.y>boxx14.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx14.x1)&&(camera.poz.x<=boxx14.x2)&&
	   (camera.poz.z<=boxx14.z1)&&(camera.poz.z>=boxx14.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx15.y2)&&(camera.poz.y>boxx15.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx15.x1)&&(camera.poz.x<=boxx15.x2)&&
	   (camera.poz.z<=boxx15.z1)&&(camera.poz.z>=boxx15.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx16.y2)&&(camera.poz.y>boxx16.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx16.x1)&&(camera.poz.x<=boxx16.x2)&&
	   (camera.poz.z<=boxx16.z1)&&(camera.poz.z>=boxx16.z2)) camera.poz.y+=1;

	if((camera.poz.y<boxx17.y2)&&(camera.poz.y>boxx17.y1)&&(pod==0)&&
	   (camera.poz.x>=boxx17.x1)&&(camera.poz.x<=boxx17.x2)&&
	   (camera.poz.z<=boxx17.z1)&&(camera.poz.z>=boxx17.z2)) camera.poz.y+=1;
	
	//œciana dolna
	if((camera.poz.y>boxx01.y1)&&(camera.poz.y<boxx01.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx01.x1)&&(camera.poz.x<=boxx01.x2)&&
	   (camera.poz.z<=boxx01.z1)&&(camera.poz.z>=boxx01.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx0.y1)&&(camera.poz.y<boxx0.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx0.x1)&&(camera.poz.x<=boxx0.x2)&&
	   (camera.poz.z<=boxx0.z1)&&(camera.poz.z>=boxx0.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx1.y1)&&(camera.poz.y<boxx1.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx1.x1)&&(camera.poz.x<=boxx1.x2)&&
	   (camera.poz.z<=boxx1.z1)&&(camera.poz.z>=boxx1.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx2.y1)&&(camera.poz.y<boxx2.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx2.x1)&&(camera.poz.x<=boxx2.x2)&&
	   (camera.poz.z<=boxx2.z1)&&(camera.poz.z>=boxx2.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx3.y1)&&(camera.poz.y<boxx3.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx3.x1)&&(camera.poz.x<=boxx3.x2)&&
	   (camera.poz.z<=boxx3.z1)&&(camera.poz.z>=boxx3.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx4.y1)&&(camera.poz.y<boxx4.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx4.x1)&&(camera.poz.x<=boxx4.x2)&&
	   (camera.poz.z<=boxx4.z1)&&(camera.poz.z>=boxx4.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx5.y1)&&(camera.poz.y<boxx5.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx5.x1)&&(camera.poz.x<=boxx5.x2)&&
	   (camera.poz.z<=boxx5.z1)&&(camera.poz.z>=boxx5.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx6.y1)&&(camera.poz.y<boxx6.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx6.x1)&&(camera.poz.x<=boxx6.x2)&&
	   (camera.poz.z<=boxx6.z1)&&(camera.poz.z>=boxx6.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx7.y1)&&(camera.poz.y<boxx7.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx7.x1)&&(camera.poz.x<=boxx7.x2)&&
	   (camera.poz.z<=boxx7.z1)&&(camera.poz.z>=boxx7.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx8.y1)&&(camera.poz.y<boxx8.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx8.x1)&&(camera.poz.x<=boxx8.x2)&&
	   (camera.poz.z<=boxx8.z1)&&(camera.poz.z>=boxx8.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx9.y1)&&(camera.poz.y<boxx9.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx9.x1)&&(camera.poz.x<=boxx9.x2)&&
	   (camera.poz.z<=boxx9.z1)&&(camera.poz.z>=boxx9.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx10.y1)&&(camera.poz.y<boxx10.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx10.x1)&&(camera.poz.x<=boxx10.x2)&&
	   (camera.poz.z<=boxx10.z1)&&(camera.poz.z>=boxx10.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx11.y1)&&(camera.poz.y<boxx11.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx11.x1)&&(camera.poz.x<=boxx11.x2)&&
	   (camera.poz.z<=boxx11.z1)&&(camera.poz.z>=boxx11.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx12.y1)&&(camera.poz.y<boxx12.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx12.x1)&&(camera.poz.x<=boxx12.x2)&&
	   (camera.poz.z<=boxx12.z1)&&(camera.poz.z>=boxx12.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx13.y1)&&(camera.poz.y<boxx13.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx13.x1)&&(camera.poz.x<=boxx13.x2)&&
	   (camera.poz.z<=boxx13.z1)&&(camera.poz.z>=boxx13.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx14.y1)&&(camera.poz.y<boxx14.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx14.x1)&&(camera.poz.x<=boxx14.x2)&&
	   (camera.poz.z<=boxx14.z1)&&(camera.poz.z>=boxx14.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx15.y1)&&(camera.poz.y<boxx15.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx15.x1)&&(camera.poz.x<=boxx15.x2)&&
	   (camera.poz.z<=boxx15.z1)&&(camera.poz.z>=boxx15.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx16.y1)&&(camera.poz.y<boxx16.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx16.x1)&&(camera.poz.x<=boxx16.x2)&&
	   (camera.poz.z<=boxx16.z1)&&(camera.poz.z>=boxx16.z2)) camera.poz.y-=1;

	if((camera.poz.y>boxx17.y1)&&(camera.poz.y<boxx17.y2)&&(pod==1)&&
	   (camera.poz.x>=boxx17.x1)&&(camera.poz.x<=boxx17.x2)&&
	   (camera.poz.z<=boxx17.z1)&&(camera.poz.z>=boxx17.z2)) camera.poz.y-=1;
}
void objekty()
{
	glPushMatrix();
	glTranslatef(0,50.0f,0);
	woda();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-63.0f,-12.5f,-10.0f);
	czajniczek();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0f,0.0f,10.0f);
	glRotatef(40, 0, 1, 0);
	cave();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,50.0f,0.0f);
	scena();
	glPopMatrix();

	glPushMatrix();
	AnT();
	glPopMatrix();
}

void ruch_stat()
{
	glTranslatef( 0.0f, -2.0f, -camera.radian );
	glRotatef( camera.obr.x, 1.0f, 0.0f, 0.0f );
}

void ruch_kam()
{
	glRotatef( camera.obr.y, 0.0f, 1.0f, 0.0f );
	glTranslatef( -camera.poz.x, -camera.poz.y, -camera.poz.z );
}

void display(void)
{
	// czyszczenie buforow
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	GLfloat ambiencik[4]={jas_sw,jas_sw,jas_sw,1.0f};
	GLfloat position[4]={10.0f, 10.0f, 100.0f, 0.0f};
	glLightfv(GL_LIGHT2, GL_POSITION, position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambiencik);
		
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHTING);

  	// flagi czynnosci pomocniczyc
    glEnable( GL_DEPTH_TEST );
	glEnable(GL_COLOR_MATERIAL);
	
	// transformacja obserwacji
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
	komp1();
	
	glPushMatrix();	
		ruch_stat();
		glTranslatef( 0.0f, 0.0f,obrot_z);
		glRotatef(obrot_x, 0.0f, 1.0f, 0.0f);
		glRotatef(obrot_y, 1.0f, 0.0f, 0.0f);
		lodka();
		ruch_kam();
		objekty();
	glPopMatrix();
	Sleep(5);
	glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
   glMatrixMode (GL_MODELVIEW);
}

void keyboard2(unsigned char key, int x, int y)
{
  switch (key) {
     case 'w':
		 xrad = (camera.obr.x / 180.0f * M_PI);
		 yrad = (camera.obr.y / 180.0f * M_PI);
		 camera.poz.y += (float)(cos(xrad)) * 0.5f;
		 camera.poz.z += (float)(sin(yrad)) * 0.5f;
		 kol();
		 kolizje();
		 kolizje_wew();
		 glutPostRedisplay();
		 break;
	 case 's':
		 xrad = (camera.obr.x / 180.0f * M_PI);
		 yrad = (camera.obr.y / 180.0f * M_PI);
		 camera.poz.y -= (float)(cos(xrad)) * 0.5f;
		 camera.poz.z -= (float)(sin(yrad)) * 0.5f;
		 kol();
		 kolizje();
		 kolizje_wew();
		 glutPostRedisplay();
		 break;
	 case 'a':
		 yrad = (camera.obr.y / 180.0f * M_PI);
		 camera.poz.x -= (float)(cos(yrad)) * 0.5f;
		 camera.poz.z -= (float)(sin(yrad)) * 0.5f;
		 kol();
		 kolizje();
		 kolizje_wew();
		 glutPostRedisplay();
		 break;
	 case 'd':
		 yrad = (camera.obr.y / 180.0f * M_PI);
		 camera.poz.x += (float)(cos(yrad)) * 0.5f;
		 camera.poz.z += (float)(sin(yrad)) * 0.5f;
		 kol();
		 kolizje();
		 kolizje_wew();
		 glutPostRedisplay();
		 break;
	 case '9':         
		 jas_sw+=0.1;
         glutPostRedisplay();
         break;
	case '0':         
		 jas_sw-=0.1;
         glutPostRedisplay();
         break;
	case 27:
		 TwTerminate();
		 exit(0);
		 break; 
	case 'z':
		 camera.obr.x+=1;
		 if( camera.obr.x > 90.0f )
		 camera.obr.x = 90.0f;
		 glutPostRedisplay();
         break;
	case 'q':
		 camera.obr.x-=1;
		 if( camera.obr.x < -30.0f )
		 camera.obr.x = -30.0f;
		 glutPostRedisplay();
         break;
	case 'j':
		 obrot_x+=1;
		 glutPostRedisplay();
         break;
	case 'l':
		 obrot_x-=1;
		 glutPostRedisplay();
         break;
	case 'i':
		 obrot_z+=1;
		 glutPostRedisplay();
         break;
	case 'k':
		 obrot_z-=1;
		 glutPostRedisplay();
         break;
	case 'u':
		 obrot_y-=1;
		 glutPostRedisplay();
         break;
	case 'o':
		 obrot_y+=1;
		 glutPostRedisplay();
         break;
  }
}

void keyboard(int key, int x, int y)
{
	switch(key)
	{
	case 100:
		camera.obr.y-=1;
		glutPostRedisplay();
		break;

	case 102:
		camera.obr.y+=1;
		glutPostRedisplay();
		break;

	case 101:
		yrad = (camera.obr.y / 180.0f * M_PI);
		xrad = (camera.obr.x / 180.0f * M_PI);
		camera.poz.x += (float)(sin(yrad));
		camera.poz.z -= (float)(cos(yrad));
		camera.poz.y -= (float)(sin(xrad));
		kol();
		kolizje();
		kolizje_wew();
		glutPostRedisplay();
		break;
	
	case 103:
		yrad = (camera.obr.y / 180.0f * M_PI);
		xrad = (camera.obr.x / 180.0f * M_PI);
		camera.poz.x -= (float)(sin(yrad));
		camera.poz.z += (float)(cos(yrad));
		camera.poz.y += (float)(sin(xrad));
		kol();
		kolizje();
		kolizje_wew();
		glutPostRedisplay();
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	int iViewport[4];
	int center_x;
	int center_y;

	if( ( button == GLUT_LEFT_BUTTON ) && ( state == GLUT_DOWN ) )
	{
		glGetIntegerv( GL_VIEWPORT, iViewport );
		center_x = iViewport[2]/2;
		center_y = iViewport[3]/2;
	}
}

void motion(int x, int y)
{
	diffx = x - camera.ost_x;
	diffy = y - camera.ost_y;

	camera.ost_x = x;
	camera.ost_y = y;

	camera.obr.x += (float) diffy;
	camera.obr.y += (float) diffx;

	if( camera.obr.x < -30.0f )
		camera.obr.x = -30.0f;
	if( camera.obr.x > 90.0f )
		camera.obr.x = 90.0f;
	
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
   int wys=1000;
   int szer=500;
	
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize (wys, szer);
   glutInitWindowPosition (0, 0);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyboard2);
   glutSpecialFunc(keyboard);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutPassiveMotionFunc(motion);
   TwWindowSize(wys,szer);
   TwInit(TW_OPENGL,NULL);
   //glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
   //glutPassiveMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
   //glutKeyboardFunc((GLUTkeyboardfun)TwEventKeyboardGLUT);
   //glutSpecialFunc((GLUTspecialfun)TwEventSpecialGLUT);
   //TwGLUTModifiersFunc(glutGetModifiers);
   glutMainLoop();
   return 0;
}
