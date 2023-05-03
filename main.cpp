#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

float win;
float aspecto;
int largura, altura;
int cor = 1;
GLfloat r1 = 0, g1 = 1, b1 = 0;
GLfloat r2 = 1, g2 = 1, b2 = 0;
GLfloat r3 = 0, g3 = 1, b3 = 0;

GLfloat escala=1, rotacao = 0;

GLfloat r = 0.59, g = 0.29, b = 0;

int submenucor;

int xax = 1;

void arvore(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.13,0.55,0.13);
        glVertex2f(0, 0);
        glVertex2f(-40, -30);
        glVertex2f(40, -30);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.13,0.55,0.13);
        glVertex2f(0, 15);
        glVertex2f(-30, -10);
        glVertex2f(30, -10);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.13,0.55,0.13);
        glVertex2f(0, 30);
        glVertex2f(-20, 10);
        glVertex2f(20, 10);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.59,0.29,0);
        glVertex2f(-4, -50);
        glVertex2f(-4, -30);
        glVertex2f(4, -30);
        glVertex2f(4, -50);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1,1,0);
        glVertex2f(0, 36);
        glVertex2f(-2.65, 28.52);
        glVertex2f(0, 30);
        glVertex2f(2.35, 28.54);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1,1,0);
        glVertex2f(-3.94, 33.47);
        glVertex2f(2.35, 28.54);
        glVertex2f(1.42, 31.51);
        glVertex2f(4.01, 33.39);
    glEnd();
}

void contorno(){
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(-win*aspecto, -win);
        glVertex2f(-win*aspecto, win);
        glVertex2f(win*aspecto, win);
        glVertex2f(win*aspecto, -win);
    glEnd();
}

void luzes(){
    glPointSize(7);
    glColor3f(r1,g1,b1);
    glBegin(GL_POINTS);
        glVertex2f(-10, 0);
        glVertex2f(5 ,5);
        glVertex2f(-3, 18);
        glVertex2f(0, -7);
        glVertex2f(10, -15);
        glVertex2f(-14, -16);
    glEnd();
    glPointSize(7);
    glColor3f(r2,g2,b2);
    glBegin(GL_POINTS);
        glVertex2f(10, -5);
        glVertex2f(-5, 5);
        glVertex2f(3 , 12);
        glVertex2f(-2, -14);
    glEnd();
    glPointSize(7);
    glColor3f(r3,g3,b3);
    glBegin(GL_POINTS);
        glVertex2f(0, 0);
        glVertex2f(-3, 10);
        glVertex2f(-10, -10);
    glEnd();

}

void montarbonecoDeNeve(){
    //cabeça
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP
       glColor3f(1, 1, 1);
        for(int i = 0; i < 350; i++){
            float theta = i*M_PI/180;
            glVertex2f (1+10*cos(theta), 8+10*sin(theta));
        }
    glEnd();
    //corpo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP
         glColor3f(1, 1, 1);
        for(int i = 0; i < 350; i++){
            float theta = i*M_PI/180;
            glVertex2f (1+20*cos(theta), -20+20*sin(theta));
        }
    glEnd();
    //olhos
    glPointSize(7);
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
        glVertex2f(-4, 10);
        glVertex2f(4 ,10);
    glEnd();
    //sobrancelha
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-6, 12);
        glVertex2f(-2, 12);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(2, 12);
        glVertex2f(6, 13);
    glEnd();
}

void chapeu(){
    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(-10, 15);
        glVertex2f(-10, 20);
        glVertex2f(12, 20);
        glVertex2f(12, 15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
      glVertex2f(-7, 20);
      glVertex2f(-7, 35);
      glVertex2f(9, 35);
      glVertex2f(9, 20);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-7, 20);
        glVertex2f(-7, 22);
        glVertex2f(9, 22);
        glVertex2f(9, 20);
    glEnd();
}

void gravata(){
    glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex2f(-3, -16);
        glVertex2f(-1.5, 0);
        glVertex2f(1.5, 0);
        glVertex2f(3, -16);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0,0,1);
        glVertex2f(0, -19);
        glVertex2f(-3, -16);
        glVertex2f(3, -16);
    glEnd();
}

void nariz(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.93,0.57,0.13);
        glVertex2f(0, 8);
        glVertex2f(-10, 5);
        glVertex2f(0, 5);
    glEnd();
}

void bonecodeNeve(){
    glPushMatrix();
        montarbonecoDeNeve();
        //funcao escala
        glScalef(escala, 1, 0);
        nariz();
	 glPopMatrix();
}

void DesenhaTexto(void *font, char *string){
    // Exibe caractere a caractere
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //primeira viewport arvore e natal
	glViewport(0, 0, largura, altura);
	glColor3f(1,1,1);
    glRasterPos2f(-30, 60);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,"Use a tecla 'L' para desligar");
    glColor3f(1,1,1);
    glRasterPos2f(-20, 50);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,"e ligar as luzes ");
	glPushMatrix();
        contorno();
		arvore();
		luzes();
	 glPopMatrix();
	 //segunda viewport boneco de neve
	glViewport(largura, 0, largura, altura);
	glColor3f(1,1,1);
    glRasterPos2f(-50, 60);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,"Use as teclas '+' e '-' para mudar o nariz ");
    glColor3f(1,1,1);
    glRasterPos2f(-50, 50);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,"e as teclas '1' e '2' para rodar a gravata ");
    glPushMatrix();
		contorno();
		//funcao translacao
		glTranslatef(0, -5, 0);
		montarbonecoDeNeve();
		bonecodeNeve();
		chapeu();
		//funcao rotacao
		glRotatef(-rotacao, 0,0,1);
		gravata();

	 glPopMatrix();

	glutSwapBuffers();
}

//timer que muda a cor das luzes
void timerCor(int troca){
    if (xax == 1 ){
        if (cor == 1){
            r1 = 0;
            g1 = 1;
            b1 = 0;
            r2 = 1;
            g2 = 1;
            b2 = 0;
            r3 = 1;
            g3 = 0;
            b3 = 0;
            cor = 2;

        } else{
            if (cor == 2){
                r1 = 1;
                g1 = 1;
                b1 = 0;
                r2 = 1;
                g2 = 0;
                b2 = 0;
                r3 = 0;
                g3 = 1;
                b3 = 0;
                cor = 3;

            }else{
                if (cor == 3){
                    r1 = 1;
                    g1 = 0;
                b1 = 0;
                r2 = 0;
                g2 = 1;
                b2 = 0;
                r3 = 1;
                g3 = 1;
                b3 = 0;
                cor = 1;
                }
            }
        }
    }else{
        r1 = 0.66;
        g1 = 0.66;
        b1 = 0.66;
        r2 = 0.66;
        g2 = 0.66;
        b2 = 0.66;
        r3 = 0.66;
        g3 = 0.66;
        b3 = 0.66;
        cor = 1;
    }

    glutPostRedisplay();
    glutTimerFunc(120,timerCor,1);
}

//menu para mudar cor do chapeu
void escolheCor(int opcao){
    switch(opcao){
        case 0:
            r = 0.58;
            g = 0;
            b = 0.83;
        break;
        case 1:
            r = 1;
            g = 0.41;
            b = 0.71;
        break;
        case 2:
            r = 0.25;
            g = 0.88;
            b = 0.82;
        break;
    }
    glutPostRedisplay();
}

void menuCor(){
    submenucor = glutCreateMenu(escolheCor);
    glutAddMenuEntry("Roxo", 0);
    glutAddMenuEntry("Rosa", 1);
    glutAddMenuEntry("Turquesa", 2);
}

void criaMenu(){
    menuCor();                                             //Chama a função que cria o submenu cor
    glutCreateMenu(0);
    glutAddSubMenu("Escolha a cor do chapeu", submenucor);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void gerenciaMouse(int botao, int estado, int x, int y){
    if(botao == GLUT_RIGHT_BUTTON)
        if(estado == GLUT_DOWN){
            criaMenu();
        }
    glutPostRedisplay();
}

void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala = escala + 0.1;
        break;
        case '-': escala = escala - 0.1;
        break;
        case '1': rotacao-=10;
        break;
        case '2': rotacao+=10;
        break;
        case 'L':
           if (xax == 1){
            xax = 2;
           } else{
               xax = 1;
           }
        break;
        case 'l':
            if (xax == 1){
            xax = 2;
           } else{
               xax = 1;
           }
        break;
    }
    glutPostRedisplay();
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){
    if(h == 0) h = 1;
    largura = w/2;
    altura = h;

    aspecto = (float) largura / altura;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);
}

void inicializa(){
     glClearColor(0,0,0,0);
     win = 80;
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Prova pratica");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(120,timerCor,1);
    glutMouseFunc(gerenciaMouse);
    glutKeyboardFunc(teclas);
    glutReshapeFunc(alteraTamanhoJanela);
    inicializa();
    glutMainLoop();
    return 0;
}
