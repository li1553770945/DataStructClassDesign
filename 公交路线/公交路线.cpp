//#include<iostream>
//#include<fstream>
//#include<stdio.h>
//#include<windows.h>
//using namespace std;
//#define OK true
//
//
//struct Station
//{
//    int* bus; //������վ��Ĺ������ı��
//    int Number;         //������վ��Ĺ���������
//    char* name;     //����
//    Station()
//    {
//        bus = new int[50];
//        name = new char[80];
//    }
//};
//
//struct Bus
//{
//    int No;        //�ù������ı��
//    int Number;     //�ù�����������վ������
//    int* route;    //�ù�������·��
//    Bus()
//    {
//        route = new int[80];
//    }
//};
//
//struct Map
//{
//    Bus* bus;          //�ó��еĹ�����
//    Station* station; //�ó��е�վ��
//    int Bus_Number;           //����������
//    int Station_Number;       //վ������
//    Map()
//    {
//        bus = new Bus[1000];
//        station = new Station[10000];
//        Bus_Number = 0;
//        Station_Number = 0;
//        int i = 0;
//        for (i = 0; i < 1000; i++)
//        {
//            bus[i].Number = 1;
//        }
//        for (i = 0; i < 10000; i++)
//        {
//            station[i].Number = 0;
//        }
//    }
//};
//
//
//typedef struct Bus_RouteInfo
//{
//    int bus;
//    int before;
//    int cur;
//} Bus_RouteInfo;
//
//
//typedef struct QNode
//{
//    Bus_RouteInfo data;
//    QNode* next;
//} QNode, * Queue;
//
//
//typedef struct
//{
//    Queue front; //��ͷָ��
//    Queue rear;  //��βָ��
//} LinkQueue;
//
//int visited[10000] = { 0 };
//
//int InitQueue(LinkQueue& Q);          //����һ���ն���Q
//int EnQueue(LinkQueue& Q, Bus_RouteInfo e); //����Ԫ��e��Ϊ�µĶ�βԪ�أ�ǰ��Q����
//Bus_RouteInfo DeQueue(LinkQueue& Q);           //�����в��գ�ɾ����ͷԪ��,������ֵ��ǰ��Q����
//int GetMap(Map& M);
//int locate_station(Map& M, char name[30]);
//int locate_bus(Map& M, int No);
//int GetBusStation(Map& M, char temp[60]);
//int LeastTransfers(Map& M, char name_1[60], char name_2[60]);
//int TraversalSite_CD(Map& M, int v1, int v2);
//bool LeastSite(Map& M, char name_1[60], char name_2[60]);
//int TraversalSite_AD(Map& M, int v1, int v2);
//void Print(Map M);
////�ϱ���԰վ,��ɽ��·������վ,��������վ
//
//
//bool LeastSite(Map& M, char name_1[60], char name_2[60])
//{
//    int v1 = locate_station(M, name_1);
//    for (int i = 1; i < 10000; i++)
//    {
//        visited[i] = 0;
//    }
//    int v2 = locate_station(M, name_2);
//    TraversalSite_AD(M, v2, v1);
//    return OK;
//}
//
//
//int TraversalSite_AD(Map& M, int v1, int v2)
//{
//    Bus_RouteInfo e[8000];
//    for (int i = 1; i < 8000; i++)
//    {
//        e[i].cur = i;
//        e[i].bus = 0;
//    }
//    Bus_RouteInfo e0;
//    int Number = 1;
//    LinkQueue Q;
//    InitQueue(Q);
//    EnQueue(Q, e[v1]);
//    visited[v1] = 1;
//    while (1)
//    {
//        int k = 1;
//        Number++;
//        e0.cur = -1;
//        EnQueue(Q, e0);
//        while (Q.front != Q.rear)
//        {
//            v1 = DeQueue(Q).cur;
//            if (v1 == -1)
//                break;
//            for (int i = 1; i <= M.station[v1].Number; i++)
//            {
//                int bus1 = locate_bus(M, M.station[v1].bus[i]);
//                for (int j = 1; j <= M.bus[bus1].Number; j++)
//                {
//                    if (M.bus[bus1].route[j] == v1)
//                    {
//                        if (M.bus[bus1].route[j + 1] == v2 || M.bus[bus1].route[j - 1] == v2)
//                        {
//                            int bus = e[v1].bus;
//                            printf("���پ���%d��վ��\n", Number);
//                            printf("%s(���,����%d·������)-->", M.station[v2].name, M.bus[bus1].No);
//                            //printf("%s(����%d·������)-->", M.station[v1].name, M.bus[bus1].No);
//                            Number--;
//                            while (Number--)
//                            {
//                                if (Number == 0)
//                                    printf("%s(�յ�)\n\n", M.station[v1].name);
//                                else
//                                    printf("%s(����%d·������)-->", M.station[v1].name, bus);
//                                v1 = e[v1].before;
//                                bus = e[v1].bus;
//                            }
//                            return 1;
//                        }
//
//                        if (!visited[M.bus[bus1].route[j - 1]] && j - 1 > 0)
//                        {
//                            e[M.bus[bus1].route[j - 1]].bus = M.bus[bus1].No;
//                            e[M.bus[bus1].route[j - 1]].before = v1;
//                            EnQueue(Q, e[M.bus[bus1].route[j - 1]]);
//                            visited[M.bus[bus1].route[j - 1]] = 1;
//                        }
//                        if (!visited[M.bus[bus1].route[j + 1]] && j + 1 <= M.bus[bus1].Number)
//                        {
//                            e[M.bus[bus1].route[j + 1]].bus = M.bus[bus1].No;
//                            e[M.bus[bus1].route[j + 1]].before = v1;
//                            EnQueue(Q, e[M.bus[bus1].route[j + 1]]);
//                            visited[M.bus[bus1].route[j + 1]] = 1;
//                        }
//                        break;
//                    }
//                }
//            }
//        }
//    }
//}
//int LeastTransfers(Map& M, char name_1[60], char name_2[60])
//{
//    int v1 = locate_station(M, name_1);
//    for (int i = 1; i < 10000; i++)
//    {
//        visited[i] = 0;
//    }
//    int v2 = locate_station(M, name_2);
//    TraversalSite_CD(M, v2, v1);
//    return 1;
//}
//int TraversalSite_CD(Map& M, int v1, int v2) //Adjacency point diffusion�ڽӵ���ɢ Connected point diffusion��ͨ����ɢ
//{
//    Bus_RouteInfo e[8000];
//    for (int i = 1; i < 8000; i++)
//    {
//        e[i].cur = i;
//        e[i].bus = 0;
//    }
//    Bus_RouteInfo e0;
//    int Number = 1;
//    LinkQueue Q;
//    InitQueue(Q);
//    EnQueue(Q, e[v1]);
//    visited[v1] = 1;
//    while (1)
//    {
//        int k = 1;
//        Number++;
//        e0.cur = -1;
//        EnQueue(Q, e0);
//        while (Q.front != Q.rear)
//        {
//            v1 = DeQueue(Q).cur;
//            if (v1 == -1)
//                break;
//            for (int i = 1; i <= M.station[v1].Number; i++)
//            {
//                int bus1 = locate_bus(M, M.station[v1].bus[i]);
//                for (int j = 1; j <= M.bus[bus1].Number; j++)
//                {
//                    if (M.bus[bus1].route[j] == v2)
//                    {
//                        int bus2;
//                        bus2 = locate_bus(M, e[v1].bus);
//                        printf("����ת%d�γ�\n", Number - 1);
//                        printf("%s(���,����%d·������)-->", M.station[v2].name, M.station[v1].bus[i]);
//                        --Number;
//                        while (Number--)
//                        {
//                            if (Number == 0)
//                                printf("%s(�յ�)\n\n", M.station[v1].name);
//                            else
//                                printf("%s(����%d·������)-->", M.station[v1].name, M.bus[bus2].No);
//                            v1 = e[v1].before;
//                            bus2 = locate_bus(M, e[v1].bus);
//                        }
//                        return 1;
//                    }
//                    if (!visited[M.bus[bus1].route[j]])
//                    {
//                        e[M.bus[bus1].route[j]].bus = M.bus[bus1].No;
//                        e[M.bus[bus1].route[j]].before = v1;
//                        EnQueue(Q, e[M.bus[bus1].route[j]]);
//                        visited[M.bus[bus1].route[j]] = 1;
//                    }
//                }
//            }
//        }
//    }
//}
//int GetBusStation(Map& M, char temp[60])
//{
//    //cout<<temp<<endl;
//    int index = locate_station(M, temp);
//    if (!index)
//    {
//        strcpy(M.station[++M.Station_Number].name, temp);
//        index = M.Station_Number;
//    }
//    M.bus[M.Bus_Number].route[M.bus[M.Bus_Number].Number] = index;
//    M.station[index].Number++;
//    M.station[index].bus[M.station[index].Number] = M.bus[M.Bus_Number].No;
//    for (int i = 0; i < 60; i++)
//    {
//        temp[i] = '\0';
//    }
//    return index;
//}
//int locate_station(Map& M, char name[60])
//{
//    for (int i = 1; i <= M.Station_Number; i++)
//    {
//        if (strcmp(M.station[i].name, name) == 0)
//            return i;
//    }
//    return 0;
//}
//int locate_bus(Map& M, int No)
//{
//    for (int i = 1; i <= M.Bus_Number; i++)
//    {
//        if (M.bus[i].No == No)
//            return i;
//    }
//    return 0;
//}
//void Print(Map M)
//{
//    for (int i = 1; i <= M.Bus_Number; i++)
//    {
//        printf("%d·\t", M.bus[i].No);
//        for (int j = 1; j <= M.bus[i].Number; j++)
//        {
//            printf("%s ", M.station[M.bus[i].route[j]].name);
//        }
//        printf("\n");
//    }
//}
//
//int GetMap(Map& M)
//{
//    int k = 0;
//    char temp[60];
//    char ch;
//    FILE* fp;
//    if ((fp = fopen("�Ͼ�������·.txt", "r")) == NULL)
//    {
//        printf("can't open this file\n");
//        system("pause");
//        exit(0);
//    }
//    for (int i = 1; i <= 1000; i++)
//    {
//        M.bus[i].Number = 1;
//    }
//    M.Bus_Number++;
//    fscanf(fp, "%d", &M.bus[M.Bus_Number].No);
//    while (ch != ' ')
//        ch = fgetc(fp);
//    while (1)
//    {
//        ch = fgetc(fp);
//        if (feof(fp))
//        {
//            temp[k] = '\0';
//            GetBusStation(M, temp);
//            break;
//        }
//        if (ch == '\n')
//        {
//            temp[k] = '\0';
//            GetBusStation(M, temp);
//            //printf("%s",bus[i].route[j]);
//            k = 0;
//            char ch2;
//            ch2 = fgetc(fp);
//            if (feof(fp))
//                break;
//            fseek(fp, -1L, 1);
//            fscanf(fp, "%d", &M.bus[++M.Bus_Number].No);
//            while (ch != ' ')
//                ch = fgetc(fp);
//            continue;
//        }
//        if (ch == ' ')
//            continue;
//        if (ch == ',')
//        {
//            temp[k] = '\0';
//            GetBusStation(M, temp);
//            //printf("%s",bus[i].route[j]);
//            k = 0;
//            M.bus[M.Bus_Number].Number++;
//            continue;
//        }
//        temp[k] = ch;
//        k++;
//    }
//    fclose(fp);
//    return 1;
//}
//
//
//int InitQueue(LinkQueue& Q)
//{
//    Q.front = (Queue)malloc(sizeof(QNode));
//    if (!Q.front)
//        exit(-2);
//    Q.front->next = NULL;
//    Q.rear = Q.front;
//    return true;
//}
//int EnQueue(LinkQueue& Q, Bus_RouteInfo e)
//{
//    Queue p = (Queue)malloc(sizeof(QNode)); //�����½��
//    if (!p)
//        exit(-2);
//    p->data = e;
//    p->next = NULL;
//    Q.rear->next = p;
//    Q.rear = p;
//    return true;
//}
//
//Bus_RouteInfo DeQueue(LinkQueue& Q)
//{
//    Bus_RouteInfo e;
//    if (Q.front == Q.rear)
//    {
//        printf("ջ��");
//        system("pause");
//        exit(0);
//    }
//    Queue p = Q.front->next;
//    e = p->data;
//    Q.front->next = p->next;
//    if (Q.rear == p)
//        Q.rear = Q.front;
//    free(p);
//    return e;
//}
//
//
//int main()
//{
//    Map M;
//    GetMap(M);
//    while (1)
//    {
//        system("cls");
//        char name_1[60], name_2[60];
//        printf("���������:");
//        scanf("%s", name_1);
//        if (strcmp(name_1, "�˳�") == 0)
//            break;
//        if (!locate_station(M, name_1))
//        {
//            printf("δ�ҵ���վ��,���������Ƿ�����!\n");
//            system("pause");
//            continue;
//        }
//        printf("�������յ�:");
//        scanf("%s", name_2);
//        if (strcmp(name_2, "�˳�") == 0)
//            break;
//        if (!locate_station(M, name_2))
//        {
//            printf("δ�ҵ���վ��,���������Ƿ�����!\n");
//            system("pause");
//            continue;
//        }
//        printf("\n����վ��·��\n");
//        LeastSite(M, name_1, name_2);
//        printf("\n����ת��·��\n");
//        LeastTransfers(M, name_1, name_2);
//        system("pause");
//    }
//    system("pause");
//    return 0;
//}