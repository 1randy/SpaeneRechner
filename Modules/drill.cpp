#include "Modules/module.h"

namespace  {
std::filesystem::path drillPath = std::filesystem::current_path() / "Daten.xlsx";
int drillIndex = 2;
}


class Drill {
public:
    static QStringList matList() {
        QStringList mat;
        int row = 2;

        xlnt::workbook wb;
        wb.load(drillPath);
        xlnt::worksheet ws = wb.sheet_by_index(drillIndex);

        while (ws.cell(1, row).to_string() != "") {
            mat.append(QString::fromStdString(ws.cell(1, row).to_string()));
            row++;
        }

        return mat;
    }

    static double Vc(int mat, int bed, int schn) {
        double Vc;
        int column = 2;

        mat = mat + 2;

        switch (bed) {
        case 2:
            column = column + 2;
            break;
        case 1:
            column = column + 1;
            break;
        default: //0
            column = column + 0;
            break;
        }

        switch (schn) {
        case 1:
            column = column + 3;
            break;
        default:
            column = column + 0;
            break;
        }

        xlnt::workbook wb;
        wb.load(drillPath);
        xlnt::worksheet ws = wb.sheet_by_index(drillIndex);

        Vc = ws.cell(column, mat).value<double>();

        return Vc;
    }

    static double fu(int mat, double D) {
        double fu;
        int column;

        mat = mat +2;

        if(D >= 16) {
            column = 12;
        }else if(D >= 12) {
            column = 11;
        }else if(D >= 8) {
            column = 10;
        }else if(D >= 5) {
            column = 9;
        }else { //D >= 2
            column = 8;
        }

        xlnt::workbook wb;
        wb.load(drillPath);
        xlnt::worksheet ws = wb.sheet_by_index(drillIndex);

        fu = ws.cell(column, mat).value<double>();

        return fu;
    }

    static int Kc(int mat) {
        int Kc;

        mat = mat + 2;

        xlnt::workbook wb;
        wb.load(drillPath);
        xlnt::worksheet ws = wb.sheet_by_index(drillIndex);

        Kc = ws.cell(13, mat).value<int>();

        return Kc;
    }

    static double Mc(int mat) {
        double Kc;

        mat = mat + 2;

        xlnt::workbook wb;
        wb.load(drillPath);
        xlnt::worksheet ws = wb.sheet_by_index(drillIndex);

        Kc = ws.cell(14, mat).value<double>();

        return Kc;
    }
};
